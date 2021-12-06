#ifndef MAP_SOLVER_MAP_SOLVER_HPP_
#define MAP_SOLVER_MAP_SOLVER_HPP_

#include "map_solver/island.hpp"
#include "map_solver/land.hpp"
#include <string>
#include <vector>

namespace map_solver
{

    /** Class to represent the algorithm to detect the islands on a map.
     */
    class MapSolver
    {
        /// The different islands the map contains.
        std::vector<Island> m_islands;
        /// Representation of the given map.
        std::vector<Land> m_map;

      public:
        MapSolver(const std::string& map_file);
        ~MapSolver() = default;

        /** Returns the islands on the map.
         *\return A vector of the islands on the map.
         */
        std::vector<Island> get_islands() const;
        /** Returns the representation of given the map.
         *\return The representation of the given map.
         */
        std::vector<Land> get_map() const;
        /// Calculates the islands on the given map.
        void calculate_islands();
    };
} // namespace map_solver
#endif
