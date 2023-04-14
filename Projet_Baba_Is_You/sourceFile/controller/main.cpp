#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"
#include "../../headerFile/model/board.h"
#include "../../headerFile/model/levelLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;
using namespace dev4;


int main() {


    LevelLoader levelLoader(0);
    Board board(levelLoader);



    return 0;
}
