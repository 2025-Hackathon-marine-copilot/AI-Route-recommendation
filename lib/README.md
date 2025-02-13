# LibNacho

&nbsp;C++로 작성하고 Boost.Python으로 빌드할 수 있는 Python 라이브러리입니다.


## Build

### Mac

&nbsp;아래와 같이 빌드합니다.

```Shell
brew install cmake boost-python3
```

&nbsp;`src`로 이동 후,

```Shell
pip install .
```
<br>

&nbsp;생성된 `.so` 파일을 사용할 디렉토리에 저장하여 사용합니다.


### Error

&nbsp;Mac 환경에서 빌드해보지 않아서 빌드 과정 중 에러가 발생할 수 있습니다. 에러 발생 시, setup.py 내 `libraries=["boost_python313"]` 부분을 사용하고 계신 Python 버전에 따라 `boost_python311` 등으로 변경하거나, `BOOST_ROOT` 위치를 변경해보시기 바랍니다.


## inner_map

- `@brief` 리스트로 지정한 구역에서 특정 지점이 해당 구역 내에 포함되는지 검사하는 함수입니다.

- `@param` 위도와 경도를 이용하여 표현한 libnacho.Point(double, double)

- `@param` 구역을 나타낼 libnacho.Point(double, double) 리스트

- `@param` libnacho.Precision(참고)

- `@return` (bool) 특정 지점의 구역 내 포함 여부


&nbsp;**구역 선분 상의 점은 구역에 포함되는 것으로 구현하였습니다.**


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


## Point

&nbsp;지도 상 한 지점을 나타내는 클래스. 매개 변수 타입은 (double, double)입니다.


## Precision

&nbsp;지정할 검사 정밀도. `default`는 `HM`입니다.

- `M`: 1m

- `HM`: 100m

- `KM`: 1km

- `HKM`: 100km
