#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"

using namespace std;
using namespace dev4;

void print(const Position & p)
{
    cout << "[ " << p.x()<< " , " << p.y() << " ]" << endl;
}

int main()
{
    Position p { 89, -45 };
    print(p);

    p = Direction::UP;
    print(p);

    p = to_position(Direction::DOWN);
    print(p);

    p = to_position(Direction::RIGHT);
    print(p);

    p = to_position(Direction::LEFT);
    print(p);

    print(Direction::UP);

    cout << endl;

    // ---------------------------------------------------------

    constexpr Position pc0 { Direction::DOWN };

    print(pc0);
    cout << endl;

    constexpr Position pc1 { to_position(Direction::UP) };

    print(pc1);
    return 0;
}
