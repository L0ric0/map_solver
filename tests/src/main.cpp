#include "map_solver/island.hpp"
#include "map_solver/map_solver.hpp"
#include <cstdio>
#include <vector>

int main()
{
    using namespace map_solver;
    int ret_code = 0;
    {
        MapSolver ms { "tests/var/map1_6islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 6) {
            std::puts("[Passed] map1_6islands.txt");
        } else {
            std::puts("[Passed] map1_6islands.txt");
            ret_code = 1;
        }
    }
    {
        MapSolver ms { "tests/var/map2_6islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 6) {
            std::puts("[Passed] map2_6islands.txt");
        } else {
            std::puts("[Passed] map2_6islands.txt");
            ret_code = 1;
        }
    }
    {
        MapSolver ms { "tests/var/map3_5islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 5) {
            std::puts("[Passed] map3_5islands.txt");
        } else {
            std::puts("[Passed] map3_5islands.txt");
            ret_code = 1;
        }
    }
    {
        MapSolver ms { "tests/var/map4_3islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 3) {
            std::puts("[Passed] map4_3islands.txt");
        } else {
            std::puts("[Passed] map4_3islands.txt");
            ret_code = 1;
        }
    }
    {
        MapSolver ms { "tests/var/map5_4islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 4) {
            std::puts("[Passed] map5_4islands.txt");
        } else {
            std::puts("[Passed] map5_4islands.txt");
            ret_code = 1;
        }
    }
    {
        MapSolver ms { "tests/var/map6_0islands.txt" };
        ms.calculate_islands();
        std::vector<Island> islands = ms.get_islands();
        if (islands.size() == 0) {
            std::puts("[Passed] map6_0islands.txt");
        } else {
            std::puts("[Passed] map6_0islands.txt");
            ret_code = 1;
        }
    }
    return ret_code;
}
