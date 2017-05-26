cmake_minimum_required(VERSION 3.4)
project(openGLExamples)
set(CMAKE_CXX_STANDARD 14)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(SOURCE_FILES main.cpp)
file(GLOB_RECURSE data Shaders/*)

add_definitions(${FissionEngine_DEFINITIONS})

include_directories(${FissionEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} FissionEngine)

add_custom_command(TARGET openGLExamples POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        $<TARGET_FILE_DIR:openGLExamples>/Shaders)

