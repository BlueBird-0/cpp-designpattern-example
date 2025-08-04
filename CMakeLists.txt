cmake_minimum_required(VERSION 3.10)

project(cpp-designpattern-example CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

# 테스트할 디렉토리 추가
add_subdirectory(Proxy)