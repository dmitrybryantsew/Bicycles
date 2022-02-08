cmake_minimum_required(VERSION 3.20)

project(Google_tests)

#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# adding the Google_Tests_run target
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(Google_Tests_run Tests/test.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Google_Tests_run Bicycles_lib GTest::gtest GTest::gtest_main)