#include "map_solver/land.hpp"

#include <utility>

namespace map_solver
{
    Land::Land(const std::pair<unsigned int, unsigned int> pos, const char sym)
        : position(pos),
          symbol(sym),
          type(char_land_type_map.at(sym))
    {
    }

    bool Land::operator<(const Land& other) const
    {
        if (position.first < other.position.first) {
            return true;
        } else if (position.second < other.position.second) {
            return true;
        }
        return false;
    }

    bool Land::operator==(const Land& other) const
    {
        return position == other.position and symbol == other.symbol and type == other.type;
    }
} // namespace map_solver
