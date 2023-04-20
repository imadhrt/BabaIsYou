//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#include "../../headerFile/controller/controller.h"
/**

Constructeur du contrôleur.
@param babaIsYou Le modèle Baba Is You.
@param view La vue du jeu Baba Is You.
*/
BabaIsYouController::BabaIsYouController(BabaIsYou *babaIsYou, BabaIsYouView *view) : babaIsYou(babaIsYou), view(view) {
    babaIsYou->registerObserver(this);
}
/**
Méthode pour traiter l'entrée de l'utilisateur.
@return La direction choisie par l'utilisateur.
*/
dev4::Direction BabaIsYouController::processInput() {
    char input;
    dev4::Direction direction;
    bool validInput = false;
    while (!validInput){
        BabaIsYouView::displayInputMessage();
        std::cin >> input;

        switch (input) {
            case 'u':
            case 'U':
                direction = dev4::Direction::UP;
                validInput = true;
                break;
            case 'l':
            case 'L':
                direction = dev4::Direction::LEFT;
                validInput = true;
                break;
            case 'd':
            case 'D':
                direction = dev4::Direction::DOWN;
                validInput = true;
                break;
            case 'R':
            case 'r':
                direction = dev4::Direction::RIGHT;
                validInput = true;
                break;
            case 'q':
            case 'Q':
                BabaIsYouView::displayGoodBye();
                exit(0);
            case 'h':
            case 'H':
                BabaIsYouView::displayHelp();
                break;
            case 'a':
            case 'A':
                babaIsYou->start(babaIsYou->getBoard()->getFile().getLevel());
                view->setBoard(*babaIsYou->getBoard());
                babaIsYou->notifyObservers();
                break;
            default:
               BabaIsYouView::displayInvalidMessage();
        }
    }
    return direction;
}

/**

Méthode pour commencer le jeu.
*/
void BabaIsYouController::start() {
    view->displayWelcomeMessage();
babaIsYou->notifyObservers();
    bool running = true;
    while (running) {

        dev4::Direction direction = processInput();

        if (direction != dev4::Direction::NONE) {
            try {
                babaIsYou->move(direction);
            }catch (std::exception exception){

            }
        } else {
            running = false;
        }

        if (babaIsYou->isWin()) {
            BabaIsYouView::displayWinMessage();
            int nextLevel = babaIsYou->getBoard()->getFile().getLevel() + 1;
            if (nextLevel <= 4) {
                view->displayBoard();
                babaIsYou->start(nextLevel);
                view->setBoard(*babaIsYou->getBoard());
                view->setBabaIsYou(*babaIsYou);
            } else {
                running = false;
            }
        }
    }

    BabaIsYouView::thanks();
}
/**

Destructeur du contrôleur.
*/
BabaIsYouController::~BabaIsYouController() {
    babaIsYou->unregisterObserver();
}

void BabaIsYouController::update() {
    view->setBabaIsYou(*babaIsYou);
    view->displayBoard();
}

