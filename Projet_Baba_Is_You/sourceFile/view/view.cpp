//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#include "../../headerFile/view/view.h"
/**
 * Affichage du board.
 */
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
/**
 * Afficher un message de bienvenue.
 */
void BabaIsYouView::displayWelcomeMessage() {
    std::cout << "Welcome to Baba Is You!" << std::endl;
}
/**
 * Afficher un message d'input.
 */
void BabaIsYouView::displayInputMessage() {
    std::cout << "Enter the command to execute (U: up, L: left, D: down, R: right, Q: quit, Z: undo, Y: redo, S: save, A: restart): ";
}
/**
 * Afficher un message de victoire  de niveau.
 */
 void BabaIsYouView::displayWinMessage() {
    std::cout << "Congratulations! You've completed the level and moved on to the next one." << std::endl;
}

/**
 * Afficher un message d'aide.
 */
 void BabaIsYouView::displayHelp() {
    std::cout << "Commandes du jeu :" << std::endl;
    std::cout << "  U, D, L, R : Déplacer le joueur" << std::endl;
    std::cout << "  Q : Quitter le jeu" << std::endl;
    std::cout << "  H : Afficher l'aide" << std::endl;
     std::cout << " A : recommencer le jeu" << std::endl;
}

 void BabaIsYouView::displayGoodBye(){
    std::cout << "Vous Avez quitté la partie !" << std::endl;
}
/**
 * Afficher un message invalide.
 */
 void BabaIsYouView::displayInvalidMessage(){
    std::cout << " Vous avez entré une direction inexistante !" << std::endl;
    displayHelp();
}

void BabaIsYouView::displaysaveSucces(){
    std::cout << "Fichier sauvgardé dans le directory levelSaved avec succés !!!!" << std::endl;
}

void BabaIsYouView::setBoard(const Board board) {
    BabaIsYouView::board = board;
}

BabaIsYouView::BabaIsYouView(Board &board, const BabaIsYou &babaIsYou) : board(board), babaIsYou(babaIsYou) {}

void BabaIsYouView::setBabaIsYou(const BabaIsYou &babaIsYou) {
    BabaIsYouView::babaIsYou = babaIsYou;
}
/**
 * Afficher un message de remerciement.
 */
void BabaIsYouView::thanks() {
    std::cout << "Merci d'avoir joué à Baba Is You!" << std::endl;
}

void BabaIsYouView::askLevelToPlay(){
    std::cout << "Appuyer sur (n) pour commencer la partie !" << std::endl;
}

void BabaIsYouView::askNameLevelToPlay() {
    std::cout << "comment s'appelle la partie sauvgardé ?" << std::endl;

}

void BabaIsYouView::askNameFileToSave(){
    std::cout << "Entrer le nombre du fichier : " << std::endl;
}
