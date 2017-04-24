cmake_minimum_required(VERSION 3.4)
project(Editor)
set(CMAKE_CXX_STANDARD 14)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(SOURCE_FILES main.cpp src/MainWindow.cpp src/MainWindow.hpp src/imgui_impl_sdl_gl3.cpp src/imgui_impl_sdl_gl3.h imgui/imconfig.h imgui/imgui.cpp imgui/imgui.h imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/imgui_internal.h imgui/stb_rect_pack.h imgui/stb_textedit.h imgui/stb_truetype.h imgui/imconfig.h imgui/imgui_dock.inl imgui/imgui_dock.h imgui/imgui_user.h imgui/imgui_user.inl src/AssetsBrowser.cpp src/AssetsBrowser.h src/MapView.cpp src/MapView.h)

add_definitions(${FissionEngine_DEFINITIONS})

include_directories(${FissionEngine_INCLUDE_DIRS})

add_definitions(${imgui_DEFINITIONS})

include_directories(${imgui_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} FissionEngine)


add_custom_command(TARGET Editor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/imgui
        $<TARGET_FILE_DIR:Editor>/imgui)
