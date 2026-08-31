cmake_minimum_required(VERSION 3.24)
project(leet-code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

function(add_leetcode_test n)
  add_executable(lc_${n} problems/${n}/test.cpp)
  target_include_directories(lc_${n} PRIVATE ${CMAKE_SOURCE_DIR})
  target_link_libraries(lc_${n} PRIVATE gtest_main)
  gtest_discover_tests(lc_${n})
endfunction()

add_executable(lc_harness tests/harness_test.cpp)
target_include_directories(lc_harness PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(lc_harness PRIVATE gtest_main)
gtest_discover_tests(lc_harness)
