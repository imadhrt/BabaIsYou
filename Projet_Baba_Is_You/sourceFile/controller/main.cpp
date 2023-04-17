#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"
#include "../../headerFile/model/board.h"


using namespace std;
using namespace dev4;


int main() {


    LevelLoader levelLoader(0);
    Board board(levelLoader);

    for (int i = 0; i < board.getFile().getHeight(); ++i) {
        for (int j = 0; j <board.getFile().getWidth() ; ++j) {
            if(board.getBoard().at(i).at(j).getListElement().at(0) == Element(Materials(Icon::EMPTY_ICON))){
                cout << toStringIcon(Icon::EMPTY_ICON) << endl;
                cout << "ivi";
            }
        }
    }

    return 0;
}
