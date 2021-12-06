#include "map_solver/map_solver.hpp"

#include "map_solver/island.hpp"
#include "map_solver/land.hpp"
#include <fstream>
#include <string>
#include <utility>

namespace map_solver
{
    MapSolver::MapSolver(const std::string& map_file)
    {
        m_map.reserve(80 * 50);
        std::ifstream map_stream { map_file };
        std::string line;
        size_t x = 0;
        while (map_stream >> line) {
            for (size_t y = 0; y < line.size(); y++) {
                Land land { std::make_pair(x, y), line[y] };
                if (land.type != LandType::Water) {
                    m_map.push_back(Land { std::make_pair(x, y), line[y] });
                }
            }
            x++;
        }
        m_map.shrink_to_fit();
    }

    void MapSolver::calculate_islands()
    {
        for (const auto& land : m_map) {
            if (land.type != LandType::Water) {
                if (m_islands.empty()) {
                    m_islands.push_back(Island { land });
                } else {
                    std::vector<std::vector<Island>::iterator> it_connected_islands;
                    for (auto it_island = m_islands.begin(); it_island != m_islands.end();
                         it_island++) {
                        if ((*it_island).add_land_part(land)) {
                            it_connected_islands.push_back(it_island);
                        }
                    }

                    if (it_connected_islands.empty()) {
                        m_islands.push_back(Island { land });
                    } else if (it_connected_islands.size() > 1) {
                        auto first = it_connected_islands[0];
                        it_connected_islands.erase(it_connected_islands.begin());
                        for (const auto& elem : it_connected_islands) {
                            (*first).add_island(*elem);
                        }
                        for (const auto& elem : it_connected_islands) {
                            m_islands.erase(elem);
                        }
                    }
                }
            }
        }
    }

    std::vector<Island> MapSolver::get_islands() const
    {
        return m_islands;
    }

    std::vector<Land> MapSolver::get_map() const
    {
        return m_map;
    }
} // namespace map_solver
