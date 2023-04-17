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
            auto element = board.getBoard().at(i).at(j).getListElement().at(board.getBoard().at(i).at(j).getListElement().size()-1);
            if (element.getMat() != nullptr && element.getWords() == nullptr) {
                cout << toStringIcon((*element.getMat()).getIcon()) << " | ";
            }else if (element.getMat() == nullptr && element.getWords() != nullptr) {
                cout << toStringSubject((*element.getWords()).getSubject().getSubjectEnum()) << " | ";

                cout << toStringOperator((*element.getWords()).getOperator().getOperatorEnum()) << " | ";
            }
        }
        cout << endl;
    }

    return 0;
}
