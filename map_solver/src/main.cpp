#include "map_solver/island.hpp"
#include "map_solver/land.hpp"
#include "map_solver/map_solver.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::cout << "MapSolver application developed by Lorenz Steinert.\n";

    std::vector<std::string> args;
    if (argc == 2) {
        args = { &argv[1], &argv[argc] };
    } else {
        std::cout << "Incorrect number of command line arguments provided.\n";
        std::cout << "Please only provide the map file as an argument.\n";
        return 1;
    }

    map_solver::MapSolver ms { args[0] };
    ms.calculate_islands();
    std::vector<map_solver::Island> islands = ms.get_islands();
    std::cout << "Number of detected landmasses: " << islands.size() << "\n";
    for (size_t i = 0; i < islands.size(); i++) {
        auto terain = islands[i].get_land();
        std::cout << "Terain information of island " << i + 1 << ":\n";
        std::cout << "\tNormal lands:\t"
                  << std::count_if(
                         terain.begin(),
                         terain.end(),
                         [](const auto& land) { return land.type == map_solver::LandType::Land; })
                  << "\n";
        std::cout << "\tTrees:\t\t"
                  << std::count_if(
                         terain.begin(),
                         terain.end(),
                         [](const auto& land) { return land.type == map_solver::LandType::Tree; })
                  << "\n";

        std::cout << "\tMountains:\t"
                  << std::count_if(
                         terain.begin(),
                         terain.end(),
                         [](const auto& land) {
                             return land.type == map_solver::LandType::Mountain;
                         })
                  << "\n";
        std::cout << "\tBuildings:\t"
                  << std::count_if(
                         terain.begin(),
                         terain.end(),
                         [](const auto& land) {
                             return land.type == map_solver::LandType::Building;
                         })
                  << "\n";
    }

    return 0;
}
