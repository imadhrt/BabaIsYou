#include <iostream>

#include "../../headerFile/model/board.h"
#include "../../headerFile/model/babaisyou.h"
#include "../../headerFile/controller/controller.h"
#include "../../headerFile/view/view.h"


using namespace std;
using namespace dev4;


int main() {




    int levelNumber = 0;
    LevelLoader levelLoader(levelNumber, false);
    Board board(levelLoader);
    BabaIsYou babaIsYou(&board);
    BabaIsYouView gameView(&babaIsYou);
    BabaIsYouController gameController(&babaIsYou,&gameView);
     gameController.start();

    return 0;
}
