//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#include "../../headerFile/view/view.h"

void BabaIsYouView::displayBoard() {

    for (int i = 0; i < babaIsYou.getBoard()->getFile().getHeight(); ++i) {
        for (int j = 0; j < babaIsYou.getBoard()->getFile().getWidth(); ++j) {
            auto element = babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().at(
                    babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().size() - 1);
            if (element.getMat() != nullptr && element.getWords() == nullptr) {
                std::cout << toStringIcon((*element.getMat()).getIcon()) << " | ";
            } else if (element.getMat() == nullptr && element.getWords() != nullptr) {
                if (&element.getWords()->getSubject() != nullptr && &element.getWords()->getOperator() == nullptr &&
                    &element.getWords()->getComplement() == nullptr) {
                    std::cout << toStringSubject((*element.getWords()).getSubject().getSubjectEnum()) << " | ";
                } else if (&element.getWords()->getSubject() == nullptr &&
                           &element.getWords()->getOperator() != nullptr &&
                           &element.getWords()->getComplement() == nullptr) {
                    std::cout << toStringOperator((*element.getWords()).getOperator().getOperatorEnum()) << " | ";
                } else {
                    std::cout << toStringComplement((*element.getWords()).getComplement().getComplementEnum()) << " | ";
                }
            }
        }
        std::cout << std::endl;
    }
}

void BabaIsYouView::displayWelcomeMessage() {
    std::cout << "Welcome to Baba Is You!" << std::endl;
}

void BabaIsYouView::displayInputMessage() {
    std::cout << "Enter the direction to move (U: up, L: left, D: down, R: right, Q: quit): ";
}

 void BabaIsYouView::displayWinMessage() {
    std::cout << "Congratulations! You've completed the level and moved on to the next one." << std::endl;
}


 void BabaIsYouView::displayHelp() {
    std::cout << "Commandes du jeu :" << std::endl;
    std::cout << "  U, D, L, R : Déplacer le joueur" << std::endl;
    std::cout << "  Q : Quitter le jeu" << std::endl;
    std::cout << "  H : Afficher l'aide" << std::endl;
}

 void BabaIsYouView::displayGoodBye(){
    std::cout << "Vous Avez quitté la partie !" << std::endl;
}

 void BabaIsYouView::displayInvalidMessage(){
    std::cout << " Vous avez entré une direction inexistante !" << std::endl;
    displayHelp();
}


void BabaIsYouView::setBoard(const Board board) {
    BabaIsYouView::board = board;
}

BabaIsYouView::BabaIsYouView(Board &board, const BabaIsYou &babaIsYou) : board(board), babaIsYou(babaIsYou) {}

void BabaIsYouView::setBabaIsYou(const BabaIsYou &babaIsYou) {
    BabaIsYouView::babaIsYou = babaIsYou;
}
