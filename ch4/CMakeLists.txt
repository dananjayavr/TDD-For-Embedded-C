cmake_minimum_required(VERSION 3.20)
project(ch4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Test Harness - Unity
add_library(Unity STATIC
  ../Unity/src/unity.c
  ../Unity/extras/fixture/src/unity_fixture.c
  ../Unity/extras/memory/src/unity_memory.c
)

target_include_directories(Unity PUBLIC
  ../Unity/src
  ../Unity/extras/fixture/src
  ../Unity/extras/memory/src

)

add_executable(led_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/src/LedDriver.c
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/unity/LedDriverTest.c
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/unity/LedDriverTestRunner.c
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/unity/AllTests.c

  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/mocks/RuntimeErrorStub.c
)

target_include_directories(led_tests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/src
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/util
)

target_compile_definitions(led_tests PUBLIC DEBUG)
target_link_libraries(led_tests PUBLIC Unity)

# Test Harness - Google Test
SET(GoogleTestRootDirectory ../googletest)
add_subdirectory(${GoogleTestRootDirectory} googletest)
add_executable(led_tests_gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/src/LedDriver.c
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/mocks/RuntimeErrorStub.c
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/google_test/LedDriverTest.cpp
)
target_include_directories(led_tests_gtest PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/src
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/util
)

target_link_libraries(led_tests_gtest
    PRIVATE
    GTest::gtest_main
)

include(CTest) # Enable testing
include(GoogleTest)
gtest_discover_tests(led_tests_gtest)
