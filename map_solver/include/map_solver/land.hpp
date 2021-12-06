#ifndef MAP_SOLVER_LAND_HPP_
#define MAP_SOLVER_LAND_HPP_

#include <unordered_map>
#include <utility>

namespace map_solver
{

    /// Enumeration to classify the different types of terain.
    enum class LandType {
        Water,
        Land,
        Tree,
        Mountain,
        Building,
    };

    /// Map to convert a char to the coresponding LandType
    static const std::unordered_map<char, LandType> char_land_type_map {
        { '.', LandType::Water },    { '+', LandType::Land },     { '*', LandType::Tree },
        { '^', LandType::Mountain }, { '@', LandType::Building },
    };

    /** This class represents a land part.
     *
     */
    struct Land {

        /// Position of the land part.
        std::pair<unsigned int, unsigned int> position;
        /// Char which the land part represents and was generated from.
        char symbol;
        /// Enum value which represents the type of terain of the land part.
        LandType type;

        Land(const std::pair<unsigned int, unsigned int> pos, const char sym);
        bool operator<(const Land& other) const;
        bool operator==(const Land& other) const;
    };
} // namespace map_solver
#endif
