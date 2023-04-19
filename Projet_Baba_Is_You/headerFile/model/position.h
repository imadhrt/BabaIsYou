#ifndef POSITION_H
#define POSITION_H

namespace dev4
{

/*
 * enum class : déclaration anticipée possible
 * => pas d'include, constexpr possible...
 *
 * à tester davantage quand même
 */
// déclaration anticipée
enum class Direction;

// définition / déclaration
class Position
{
    int x_ { 0 };
    int y_ { 0 };

  public:

    constexpr Position() = default;
    constexpr Position(int x, int y);
    constexpr Position(Direction e);

    constexpr Position nextPos(Direction direction);

    constexpr int x() const;
    constexpr void x(int x);

    constexpr int y() const;
    constexpr void y(int y);
};

// implémentation

constexpr Position::Position(int x, int y) :
    x_ { x }, y_ { y }
{ }

// définition / déclaration

constexpr Position dir_to_pos [] =
{ /* UP */ Position { -1, 0 }, /* DOWN */ Position { +1, 0 },/* RIGHT */ Position { 0, +1 },/* LEFT */ Position { 0, -1 } };

/*
 * dir_to_pos est implicitement static => une variable différente créée
 * pour chaque fichier .cpp qui l'utilise via inclusion de position.h
 *
 * https://stackoverflow.com/questions/92546/variable-declarations-in-header-files-static-or-not
 * https://stackoverflow.com/a/59307821
 *
 * donc tout est ok :-)
 */

// implémentation (suite)

constexpr Position::Position(Direction e) :
    Position { dir_to_pos[static_cast<int>(e)] }
{ }

constexpr int Position::x() const
{
    return x_;
}

constexpr void Position::x(int x)
{
    x_ = x;
}

constexpr int Position::y() const
{
    return y_;
}

constexpr void Position::y(int y)
{
    y_ = y;
}

constexpr Position Position::nextPos(Direction direction){
    Position offset = dir_to_pos[static_cast<int>(direction)];
    return Position(x_ + offset.x(), y_ + offset.y());
}

} // namespace dev4

#endif // POSITION_H
