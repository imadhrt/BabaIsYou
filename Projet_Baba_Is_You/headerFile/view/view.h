//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_VIEW_H
#define PROJET_BABA_IS_YOU_VIEW_H
#include <iostream>
#include "../model/board.h"
#include "../model/babaisyou.h"

class BabaIsYouView {
private:
    Board& board;
    BabaIsYou babaIsYou;
public:

    BabaIsYouView(Board &board);

    void setBabaIsYou(const BabaIsYou &babaIsYou);

    void displayBoard();

    void setBoard(const Board board);

    BabaIsYouView(Board &board, const BabaIsYou &babaIsYou);

    static void thanks();

    static void displayWelcomeMessage();
    static void displayInputMessage();
    static void displayWinMessage();
    static void displayHelp();
    static void displayGoodBye();
    static void displayInvalidMessage();
    static void askLevelToPlay();
    static void askNameLevelToPlay();
    static void askNameFileToSave();
    static void displaysaveSucces();
};
#endif //PROJET_BABA_IS_YOU_VIEW_H
