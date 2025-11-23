cmake_minimum_required(VERSION 3.20)
project(ch2s)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Test Harness - CppUTest

SET(CppUTestRootDirectory ../cpputest)

# Either set CPPUTEST_PLATFORM to one of the provided platforms under
# /src/Platforms/, or provide a project-specific
# platform.cpp (as shown below)
# set(CPPUTEST_PLATFORM OFF CACHE BOOL "Platform implementation")
# add_subdirectory(${CppUTestRootDirectory} CppUTest)
# target_sources(CppUTest
#     PRIVATE
#         ${PROJECT_SOURCE_DIR}/UtestPlatform.cpp
# )

# Here I'm setting the Platform to one of the supported platforms
SET(CPPUTEST_PLATFORM Gcc)
add_subdirectory(${CppUTestRootDirectory} CppUTest)
add_executable(app_cpputest cpputest/main.cpp)
target_link_libraries(app_cpputest
    PRIVATE
        CppUTest::CppUTest
        #or CppUTest::CppUTestExt
)

include(CTest) # Enable testing

# automatically discover CppUTest tests
include(CppUTest)
cpputest_discover_tests(app_cpputest)


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

add_executable(app_simple unity/main_simple.c)
add_executable(app_fixtures unity/main_fixtures.c)

target_include_directories(app_simple PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)
target_include_directories(app_fixtures PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)

target_compile_definitions(app_simple PUBLIC DEBUG)
target_link_libraries(app_simple PUBLIC Unity)
target_compile_definitions(app_fixtures PUBLIC DEBUG)
target_link_libraries(app_fixtures PUBLIC Unity)


# Test Harness - Google Test

SET(GoogleTestRootDirectory ../googletest)
add_subdirectory(${GoogleTestRootDirectory} googletest)
add_executable(app_googletest googletest/main.cpp)
target_link_libraries(app_googletest
    PRIVATE
    GTest::gtest_main
)

include(CTest) # Enable testing
include(GoogleTest)
gtest_discover_tests(app_googletest)