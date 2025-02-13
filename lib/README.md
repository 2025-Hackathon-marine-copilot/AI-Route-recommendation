# LibNacho

&nbsp;C++로 작성 후 Boost.Python으로 빌드한 Python 라이브러리입니다.


## Build - Mac

&nbsp;아래와 같이 빌드합니다.

```Shell
brew install cmake boost-python3
```

&nbsp;`setup.py` 위치로 이동 후,

```Shell
pip install .
```


## Example

```Python
import libnacho

# 검사 구역 지정
map = [ libnacho.Point(0.0, 0.0),
        libnacho.Point(0.0, 10.0),
        libnacho.Point(10.0, 10.0),
        libnacho.Point(10.0, 0.0) ]

# 검사 지점 지정
point = [ libnacho.Point(5.0, 5.0),
        libnacho.Point(-5.0, -5.0),
        libnacho.Point(10.0, 5.0),
        libnacho.Point(0.0, 0.0) ]

# 검사 정밀도 지정
precision = libnacho.Precision.M

# 각 검사 지점에 대해 inner_map 함수 호출
for i, point in enumerate(points):
        result = libnacho.inner_map(point, map, precision)
        print(f"Point {i+1}: {point.lat}, {point.lon} -> Inner Map Result: {result}")
```


## inner_map

- `@brief` 리스트로 지정한 구역에서 특정 지점이 해당 구역 내에 포함되는지 검사하는 함수입니다.

- `@param` 위도와 경도를 이용하여 표현한 libnacho.Point(double, double)

- `@param` 구역을 나타낼 libnacho.Point(double, double) 리스트

- `@param` libnacho.Precision(참고)

- `@return` (bool) 특정 지점의 구역 내 포함 여부


## Point

&nbsp;지도 상 한 지점을 나타내는 클래스. 매개 변수 타입은 (double, double)입니다.


## Precision

&nbsp;지정할 검사 정밀도. default는 HM입니다.

- `M`: 1m

- `HM`: 100m

- `KM`: 1km

- `HKM`: 100km
