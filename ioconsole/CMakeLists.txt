cmake_minimum_required(VERSION 3.4)
project(ioconsole)

#Version
set (FIENE_VERSION_MAJOR 0)
set (FIENE_VERSION_MINOR 1)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion -fno-math-errno")


add_library(${PROJECT_NAME} STATIC ${FIENE_SRC} main.cpp main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC Engine)


# Required on Unix OS family to be able to be linked into shared libraries.
set_target_properties(${PROJECT_NAME}
        PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

target_link_libraries(${PROJECT_NAME})


set(${PROJECT_NAME}_DEFINITIONS CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

# Expose A's public includes (including the ones of A's dependencies
# transitively) to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

