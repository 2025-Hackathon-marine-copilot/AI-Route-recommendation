from setuptools import setup, Extension
import os

# Boost 설치 경로 (Homebrew로 설치한 경우)
BOOST_ROOT = "/opt/homebrew"  # Homebrew 경로
PYTHON_INCLUDE = os.popen("python3 -c 'from sysconfig import get_paths; print(get_paths()[\"include\"])'").read().strip()

# C++ 확장 모듈 설정
module = Extension(
    "libnacho",  # 생성할 Python 모듈 이름
    sources=["bindings.cpp", "libnacho.cpp"],  # 소스 파일 목록
    include_dirs=[PYTHON_INCLUDE, f"{BOOST_ROOT}/include"],  # Boost 및 Python 헤더 파일 경로
    library_dirs=[f"{BOOST_ROOT}/lib"],  # Boost 라이브러리 경로
    libraries=["boost_python313"],  # 사용 중인 Python 버전에 맞는 Boost.Python 라이브러리
    extra_compile_args=["-std=c++20"],  # C++ 20 이상 사용
)

setup(
    name="libnacho",
    version="1.0",
    ext_modules=[module],
)
