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

# Development Target
add_executable(adder_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/ch4/Adder/src/Add.c
  ${CMAKE_CURRENT_SOURCE_DIR}/ch4/Adder/test/AddTestRunner.c
)

target_include_directories(adder_tests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ch4/Adder/src
)

target_compile_definitions(adder_tests PUBLIC DEBUG)
target_link_libraries(adder_tests PUBLIC Unity)

# Embedded Target
add_executable(adder_tests_stm32
  ${CMAKE_CURRENT_SOURCE_DIR}/ch4/Adder/src/Add.c
  ${CMAKE_CURRENT_SOURCE_DIR}/ch4/Adder/test/AddTestRunner.c
)
