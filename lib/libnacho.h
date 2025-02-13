#ifndef LIBNACHO_H
#define LIBNACHO_H

#define LIBNACHO_VERSION "1.0.0"

#include <cstddef>
#include <vector>

namespace nacho
{
        class Point
        {
        public:
                Point(double latitude, double longitude): lat(latitude), lon(longitude) {  }

                double lat, lon;
        };

        enum Precision
        {
                M, // 1m
                HM, // 100m
                KM, // 1km
                HKM // 100km
        };
}

/**
 * @brief 지점 p가 구역 map 내부에 있는지 확인하는 함수
 */
bool inner_map(const nacho::Point& p, const std::vector<nacho::Point>& map, const nacho::Precision& precision = nacho::Precision::HM);
#endif
