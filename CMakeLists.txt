cmake_minimum_required(VERSION 3.24)
project(leet-code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

file(GLOB leet_tests RELATIVE ${CMAKE_SOURCE_DIR} problems/*/test.cpp)
foreach(test_path ${leet_tests})
  string(REGEX MATCH "problems/([0-9]+)/test.cpp" _ "${test_path}")
  set(n ${CMAKE_MATCH_1})
  add_executable(${n} ${CMAKE_SOURCE_DIR}/${test_path})
  target_include_directories(${n} PRIVATE ${CMAKE_SOURCE_DIR})
  target_link_libraries(${n} PRIVATE gtest_main)
  gtest_discover_tests(${n})
endforeach()

add_executable(lc_harness tests/harness_test.cpp)
target_include_directories(lc_harness PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(lc_harness PRIVATE gtest_main)
gtest_discover_tests(lc_harness)
