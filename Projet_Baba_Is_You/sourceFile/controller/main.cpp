#include <iostream>

#include "../../headerFile/model/position.h"
#include "../../headerFile/model/direction.h"
#include "../../headerFile/model/board.h"
#include "../../headerFile/model/babaisyou.h"
#include "../../headerFile/controller/controller.h"
#include "../../headerFile/view/view.h"


using namespace std;
using namespace dev4;


int main() {


    /*LevelLoader levelLoader(0);
    Board board(levelLoader);
    BabaIsYou babaIsyou(&board);

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


    babaIsyou.move(Direction::RIGHT);
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
    cout << endl;
*/


    // Charger le premier niveau
    int levelNumber = 0;
    LevelLoader levelLoader(levelNumber);
    Board board(levelLoader);
    BabaIsYou babaIsYou(&board);
    BabaIsYouView gameView(board,babaIsYou);
    BabaIsYouController gameController(&babaIsYou,&gameView);



    gameController.start();

    babaIsYou.getVecPosPlayer();
    return 0;
}
