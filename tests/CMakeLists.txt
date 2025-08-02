
# 경로 설정
set(GTEST_ROOT "C:/libs/googletest")
set(GTEST_LIB_DIR "${GTEST_ROOT}/build/lib")
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/googletest/include")

# 인클루드 디렉토리 추가
include_directories(${GTEST_INCLUDE_DIR})

# 라이브러리 디렉토리 추가
link_directories(${GTEST_LIB_DIR})

# 모든 `_test.cpp` 파일을 자동으로 찾아 TEST_SOURCES 변수에 저장합니다.
file(GLOB TEST_SOURCES "*_test.cpp")

# 테스트를 위한 실행 파일(run_tests)을 생성합니다.
# 이제 TEST_SOURCES 변수를 사용하여 모든 테스트 파일을 한 번에 추가합니다.
add_executable(run_tests ${TEST_SOURCES})

# run_tests에 gtest와 gmock 라이브러리를 링크합니다.
# gtest_main은 테스트 실행을 위한 main() 함수를 포함하고 있어 편리합니다.
target_link_libraries(run_tests PRIVATE gtest_main gmock gtest)
include(GoogleTest)
gtest_discover_tests(run_tests)