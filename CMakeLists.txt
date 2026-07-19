cmake_minimum_required(VERSION 3.20)

project(
    libdoodle
    VERSION 0.1.0
    DESCRIPTION "A lightweight C++ plotting and diagram library."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(DOODLE_BUILD_SHARED "Build shared library" OFF)

if(DOODLE_BUILD_SHARED)
    add_library(doodle SHARED)
else()
    add_library(doodle STATIC)
endif()

target_sources(doodle PRIVATE
    src/svg.cpp
    src/diagram.cpp
    src/flowchart.cpp
    src/gnuplot.cpp
    src/plot.cpp
)

target_include_directories(doodle
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include

    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

if(MSVC)
    target_compile_options(doodle PRIVATE /W4)
else()
    target_compile_options(doodle PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

target_compile_features(doodle PUBLIC cxx_std_20)

add_executable(test_plot tests/test_plot.cpp)

target_link_libraries(test_plot PRIVATE doodle)