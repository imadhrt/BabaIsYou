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
    std::vector<dev4::Position > playerPos;

    bool contains(const std::vector<Element>& vec, Icon icon);
public:
    const Board &getBoard() const;

    const RuleManager &getRules() const;

    void findAndAddRules();

    const std::vector<dev4::Position> &getPlayerPos() const;

    void setEffetToSubject();

    void applyRule();

    explicit BabaIsYou(const Board &board);

    std::vector<dev4::Position> getVecPosPlayer();

    bool isPossibleMove(dev4::Direction dir, dev4::Position pos);

};

#endif //PROJET_BABA_IS_YOU_BABAISYOU_H
