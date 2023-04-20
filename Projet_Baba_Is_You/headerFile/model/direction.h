#ifndef DIRECTION_H
#define DIRECTION_H

// ici include pour constexpr
#include "position.h"

namespace dev4
{

// définition / déclaration

enum class Direction
{
    UP, DOWN, RIGHT, LEFT,NONE
};

// prototypes

constexpr Position to_position(Direction d);

// implémentations

constexpr Position to_position(Direction d)
{
    return dir_to_pos[static_cast<int>(d)];
}

} // namespace dev4

#endif // DIRECTION_H
