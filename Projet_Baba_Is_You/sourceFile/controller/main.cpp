#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"
#include "../../headerFile/model/board.h"
#include "../../headerFile/model/babaisyou.h"


using namespace std;
using namespace dev4;


int main() {


    LevelLoader levelLoader(3);
    Board board(levelLoader);
    BabaIsYou babaIsyou(board);
    //babaIsyou.applyTransform();

    for (int i = 0; i < board.getFile().getHeight(); ++i) {
        for (int j = 0; j <board.getFile().getWidth() ; ++j) {
            auto element = board.getBoard().at(i).at(j).getListElement().at(board.getBoard().at(i).at(j).getListElement().size()-1);
            if (element.getMat() != nullptr && element.getWords() == nullptr) {
                cout << toStringIcon((*element.getMat()).getIcon()) << " | ";
            }else if (element.getMat() == nullptr && element.getWords() != nullptr) {
                if(&element.getWords()->getSubject() != nullptr && &element.getWords()->getOperator() == nullptr && &element.getWords()->getComplement()== nullptr) {
                    cout << toStringSubject((*element.getWords()).getSubject().getSubjectEnum()) << " | ";
                }else if(&element.getWords()->getSubject() == nullptr && &element.getWords()->getOperator() != nullptr && &element.getWords()->getComplement()== nullptr){
                    cout << toStringOperator((*element.getWords()).getOperator().getOperatorEnum()) << " | ";
                }else{
                    cout << toStringComplement((*element.getWords()).getComplement().getComplementEnum()) << " | ";
                }
            }
        }
        cout << endl;
    }


    babaIsyou.findAndAddRules();
    auto list = babaIsyou.getRules().getListOfRules();
    vector<dev4::Position> vec = babaIsyou.getVecPosPlayer();
    vector<dev4::Position> vec2 = babaIsyou.getPlayerPos();

    Position pos = vec.at(4);
    bool test;
    test = babaIsyou.isPossibleMove(Direction::RIGHT, pos);

    int c = babaIsyou.push(pos,Direction::RIGHT);

    pos = babaIsyou.getPositionAfterPush(pos,dev4::Direction::RIGHT);

    bool test2 = babaIsyou.isPossibleMove(Direction::RIGHT, pos);
    return 0;
}
