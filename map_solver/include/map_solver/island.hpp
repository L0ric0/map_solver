#ifndef MAP_SOLVER_ISLAND_HPP_
#define MAP_SOLVER_ISLAND_HPP_

#include "map_solver/land.hpp"
#include <set>

namespace map_solver
{
    /** This class represents an Island.
     *
     * An Interface is provided that allows to retrieve the parts of the island as well as checking
     * if another part can be added and adding sayed part. Futhermore a member function is provided
     * to merge another island into this one.
     *
     */
    class Island
    {
        /// Set containing the land parts of the island.
        std::set<Land> m_land_mass;

      public:
        Island(const Land& land);
        ~Island() = default;
        bool operator==(const Island& other) const;

        /// Returns the land parts of the island.
        std::set<Land> get_land() const;

        /** Checks if the provided land part can be added to the island.
         *
         * \param[in] land The land part to check.
         * \return True if the land part can be added to the island.
         */
        bool is_land_part(const Land& land) const;

        /** Checks and add the provided land part to the island if possible.
         *
         * Checks if the provided land part can be added to the island and if so add it to the
         * island. If successfull returns True.
         *
         * \param[in] land The land part to add.
         * \return True if sucessfull.
         */
        bool add_land_part(const Land& land);
        /** Checks and merges the provided island to the island if possible.
         *
         * Checks if the provided island can be merged into the island and does so if possible.
         * if successfull return True.
         *
         * \param[in] island The island to merge into this one.
         * \return True if sucessfull.
         */
        bool add_island(const Island& island);
    };
} // namespace map_solver
#endif
