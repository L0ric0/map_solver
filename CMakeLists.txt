cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(map_solver VERSION 0.0.1)

include(PreventInSourceBuilds)
include(StandardProjectSettings)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

add_library(project_warnings INTERFACE)
include(CompilerWarnings)
set_project_warnings(project_options)

include(StaticAnalyzers)

include(Doxygen)
enable_doxygen()

option(BUILD_TESTING "Enable compilation of tests" OFF)
option(ENABLE_COVERAGE "Generate coverage reports." OFF)

if(BUILD_TESTING)
    enable_testing()
    message("Building Tests.")
    if(ENABLE_COVERAGE)
        include(CodeCoverage)
    endif()
    add_subdirectory(tests)
endif()

add_subdirectory(map_solver)
