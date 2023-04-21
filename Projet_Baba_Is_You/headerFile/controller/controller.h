//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_CONTROLLER_H
#define PROJET_BABA_IS_YOU_CONTROLLER_H

#include "../model/babaisyou.h"
#include "../view/view.h"

class BabaIsYouController : public Observer{
public:
    BabaIsYouController(BabaIsYou *babaIsYou, BabaIsYouView *view);
    void start();

    ~BabaIsYouController() override;
    void update() override;
    int lireChiffreClavier();
    char beforeGame();
private:
    BabaIsYou *babaIsYou;
    BabaIsYouView *view;
    dev4::Direction processInput();
};
#endif //PROJET_BABA_IS_YOU_CONTROLLER_H
