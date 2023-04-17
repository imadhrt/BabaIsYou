//
// Created by Mamoun benmassaoud on 17/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_BABAISYOU_H
#define PROJET_BABA_IS_YOU_BABAISYOU_H

#include "board.h"
#include "ruleManager.h"

class BabaIsYou{
private:
    Board board;
    RuleManager rules;
public:
    const Board &getBoard() const;

    const RuleManager &getRules() const;

    void findAndAddRules();

    void setEffetToSubject();

    void applyRule();

    explicit BabaIsYou(const Board &board);

};

#endif //PROJET_BABA_IS_YOU_BABAISYOU_H
