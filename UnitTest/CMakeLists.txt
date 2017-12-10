cmake_minimum_required(VERSION 3.4)
project(UnitTest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion -fno-math-errno")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(SOURCE_FILES main.cpp vec.t.cpp ../SnakeGame/Source/main.cpp)
file(GLOB_RECURSE data Shaders/*)

add_definitions(${FissionEngine_DEFINITIONS})

include_directories(${FissionEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} FissionEngine)


