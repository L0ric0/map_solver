#include "map_solver/island.hpp"

#include "map_solver/land.hpp"
#include <set>

namespace map_solver
{

    Island::Island(const Land& land)
    {
        m_land_mass.insert(land);
    }

    bool Island::is_land_part(const Land& land) const
    {
        for (const auto& elem : m_land_mass) {
            if ((elem.position.first == land.position.first
                 and elem.position.second == land.position.second)
                or (elem.position.first == land.position.first
                    and elem.position.second == land.position.second - 1)
                or (elem.position.first == land.position.first
                    and elem.position.second == land.position.second + 1)
                or (elem.position.first == land.position.first - 1
                    and elem.position.second == land.position.second)
                or (elem.position.first == land.position.first + 1
                    and elem.position.second == land.position.second)
                or (elem.position.first == land.position.first - 1
                    and elem.position.second == land.position.second - 1)
                or (elem.position.first == land.position.first - 1
                    and elem.position.second == land.position.second + 1)
                or (elem.position.first == land.position.first + 1
                    and elem.position.second == land.position.second - 1)
                or (elem.position.first == land.position.first + 1
                    and elem.position.second == land.position.second + 1)) {
                return true;
            }
        }
        return false;
    }

    bool Island::add_land_part(const Land& land)
    {
        if (is_land_part(land)) {
            m_land_mass.insert(land);
            return true;
        }
        return false;
    }

    bool Island::add_island(const Island& island)
    {
        auto other_lands = island.get_land();
        for (const auto& elem : other_lands) {
            if (is_land_part(elem)) {
                {
                    m_land_mass.merge(other_lands);
                }
                return true;
            }
        }
        return false;
    }

    std::set<Land> Island::get_land() const
    {
        return m_land_mass;
    }

    bool Island::operator==(const Island& other) const
    {
        if (m_land_mass.size() != other.m_land_mass.size()) {
            return false;
        }
        return m_land_mass == other.m_land_mass;
    }
} // namespace map_solver
