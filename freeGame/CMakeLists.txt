cmake_minimum_required(VERSION 3.4)
project(freeGame)
set(CMAKE_CXX_STANDARD 14)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(SOURCE_FILES src/main.cpp)
file(GLOB_RECURSE data Shaders/*)

add_definitions(${FissionEngine_DEFINITIONS})

include_directories(${FissionEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} FissionEngine)

add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        $<TARGET_FILE_DIR:freeGame>/Shaders)

add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Textures
        $<TARGET_FILE_DIR:freeGame>/Textures)

add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Levels
        $<TARGET_FILE_DIR:freeGame>/Levels)


add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Fonts
        $<TARGET_FILE_DIR:freeGame>/Fonts)

add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Sounds
        $<TARGET_FILE_DIR:freeGame>/Sounds)

add_custom_command(TARGET freeGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Scripts
        $<TARGET_FILE_DIR:freeGame>/Scripts)


