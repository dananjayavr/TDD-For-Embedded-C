cmake_minimum_required(VERSION 3.20)
project(ch3)

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
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/LedDriverTest.c
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/LedDriverTestRunner.c
  ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/test/AllTests.c 
)

add_executable(cb_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/CircularBuffer/src/CircularBuffer.c
  ${CMAKE_CURRENT_SOURCE_DIR}/CircularBuffer/test/CircularBufferTest.c
  ${CMAKE_CURRENT_SOURCE_DIR}/CircularBuffer/test/CircularBufferTestRunner.c
  ${CMAKE_CURRENT_SOURCE_DIR}/CircularBuffer/test/AllTests.c
)

target_include_directories(led_tests PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/LedDriver/src 
)

target_include_directories(cb_tests PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/CircularBuffer/src 
)

target_compile_definitions(led_tests PUBLIC DEBUG)
target_link_libraries(led_tests PUBLIC Unity)

target_compile_definitions(cb_tests PUBLIC DEBUG)
target_link_libraries(cb_tests PUBLIC Unity)
