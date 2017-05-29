cmake_minimum_required(VERSION 3.4)
project(FieneToolKit)
set(CMAKE_CXX_STANDARD 14)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(SOURCE_FILES Source/main.cpp Source/imgui_impl_sdl_gl3.cpp Source/imgui_impl_sdl_gl3.hpp imgui/imconfig.h imgui/imgui.cpp imgui/imgui.h imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_internal.h imgui/stb_rect_pack.h imgui/stb_textedit.h imgui/stb_truetype.h imgui/imconfig.h Source/MainWindow.cpp Source/MainWindow.hpp Source/MapEditor.cpp Source/MapEditor.hpp Source/MapDocument.cpp Source/MapDocument.hpp Source/AssetsBrowser.cpp Source/AssetsBrowser.hpp)
file(GLOB_RECURSE data Shaders/*)

add_definitions(${FissionEngine_DEFINITIONS})

include_directories(${FissionEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} FissionEngine)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/Assets)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/Shaders)

