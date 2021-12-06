add_executable(map_solver
    "src/main.cpp"
    "include/map_solver/island.hpp" "src/island.cpp"
    "include/map_solver/land.hpp" "src/land.cpp"
    "include/map_solver/map_solver.hpp" "src/map_solver.cpp"
)

add_executable(map_solver::map_solver ALIAS map_solver)

target_link_libraries(map_solver PRIVATE project_options
                                     project_warnings)

target_include_directories(map_solver PUBLIC include)
