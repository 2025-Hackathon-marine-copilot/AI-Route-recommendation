#include "libnacho.h"

#include <cmath>

namespace nacho
{
        class Point_l
        {
        public:
                Point_l(const Point& p, long long int precision): lat(static_cast<long long int>(p.lat * precision)), lon(static_cast<long long int>(p.lon * precision)) {  }
                
                long long int lat, lon;
        };
}

/**
 * @brief 선분 a-b와 선분 a-c의 외적을 구하는 함수
 */
static long long int cross_product(const nacho::Point_l& a, const nacho::Point_l& b, const nacho::Point_l& c);

/**
 * @brief precision에 대응하는 정밀도 계수를 구하는 함수
 */
static long long int get_precision(const nacho::Precision& precision);

/**
 * @brief 지점 p가 선분 start-end 상에 있는지 확인하는 함수
 */
static bool is_on_segment(const nacho::Point_l& p, const nacho::Point_l& start, const nacho::Point_l& end);

bool inner_map(const nacho::Point& p, const std::vector<nacho::Point>& map, const nacho::Precision& precision)
{
        // winding number
        std::size_t wn = 0;

        // 지도 상 정확도 설정
        long long int ps = get_precision(precision);

        // 연산 속도를 위해 long long int로 변환
        nacho::Point_l p_l{p, ps};

        std::size_t n = map.size();
        for(std::size_t i = 0; i < n; i++) {
                // map 선분 시작점, 끝점
                nacho::Point_l start{map[i], ps};
                nacho::Point_l end{map[(i + 1) % n], ps};

                // 지점이 선분 상에 있으면 구역 내로 판정
                if(is_on_segment(p_l, start, end))
                        return true;

                // p 기준 아래로 내려오는 선분인 경우
                if((start.lon > p_l.lon) && (end.lon <= p_l.lon)) {
                        // p 기준 오른쪽에 있는 선분인 경우
                        if(cross_product(start, end, p_l) < 0)
                                wn++;
                }
                // p 기준 위로 올라오는 선분인 경우
                else if((start.lon <= p_l.lon) && (end.lon > p_l.lon)) {
                        // p 기준 왼쪽에 있는 선분인 경우
                        if(cross_product(start, end, p_l) > 0)
                                wn--;
                }
        }

        // p가 map 내부에 있으면 wn이 0이 아님
        return wn != 0;
}

static long long int cross_product(const nacho::Point_l& a, const nacho::Point_l& b, const nacho::Point_l& c)
{
        return (b.lat - a.lat) * (c.lon - a.lon) - (c.lat - a.lat) * (b.lon - a.lon);
}

static long long int get_precision(const nacho::Precision& precision)
{
        long long int ps = 10000;

        switch(precision) {
                case nacho::Precision::M:
                        ps = 1000000;

                        break;
                case nacho::Precision::HM:
                        ps = 10000;

                        break;
                case nacho::Precision::KM:
                        ps = 1000;

                        break;
                case nacho::Precision::HKM:
                        ps = 10;

                        break;
                default:
                        ps = 10000;

                        break;
        }

        return ps;
}

static bool is_on_segment(const nacho::Point_l& p, const nacho::Point_l& start, const nacho::Point_l& end)
{
        // 외적 결과가 0이면 start-end 일직선 상
        if(cross_product(start, end, p) == 0) {
                // p가 start-end 범위 내에 있으면 선분 상의 점
                if((p.lat <= std::max(start.lat, end.lat) && p.lat >= std::min(start.lat, end.lat))
                        && (p.lon <= std::max(start.lon, end.lon) && p.lon >= std::min(start.lon, end.lon)))
                        return true;
                else
                        return false;
        } else
                return false;
}
