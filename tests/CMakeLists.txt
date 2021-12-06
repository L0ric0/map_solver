set(BINARY unit_tests)

add_executable(${BINARY} EXCLUDE_FROM_ALL
    "src/main.cpp"
    "../map_solver/include/map_solver/island.hpp" "../map_solver/src/island.cpp"
    "../map_solver/include/map_solver/land.hpp" "../map_solver/src/land.cpp"
    "../map_solver/include/map_solver/map_solver.hpp" "../map_solver/src/map_solver.cpp"
)

target_include_directories(${BINARY} PRIVATE include)
target_include_directories(${BINARY} PRIVATE ../map_solver/include)

target_link_libraries(${BINARY} PRIVATE project_warnings project_options)

if (COVERAGE)
        append_coverage_compiler_flags()
        setup_target_for_coverage_gcovr_html(
            NAME ${CMAKE_PROJECT_NAME}_coverage
            EXECUTABLE ctest -j ${PROCESSOR_COUNT}
            DEPENDENCIES ${BINARY}
            EXCLUDE ${PROJECT_SOURCE_DIR}/tests
        )
endif()
