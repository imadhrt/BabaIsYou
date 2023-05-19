//
// Created by Mamoun benmassaoud on 17/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_BABAISYOU_H
#define PROJET_BABA_IS_YOU_BABAISYOU_H

#include "board.h"
#include "ruleManager.h"
#include "direction.h"
#include "../util/observer.h"
#include "../util/observable.h"
#include "managerCommand.h"

class BabaIsYou : public Observable{
private:
    Board *board;
    RuleManager rules;

    std::vector<dev4::Position > playerPos;
    std::vector<Observer*> observers;

    ManagerCommand managerCommand;

    void transform(Subject firstSubject, Subject secondSubject);
    bool contains(const std::vector<Element>& vec, Icon icon);
public:
    Board *getBoard() const;

    void start(int level, bool isSave);

    void setBoard(Board *board);

    const RuleManager &getRules() const;

    void findAndAddRules();

    const std::vector<dev4::Position> &getPlayerPos() const;

    void setEffetToSubject();

    explicit BabaIsYou(Board *board);

    std::vector<dev4::Position> getVecPosPlayer();

    bool isPossibleMove(dev4::Direction dir, dev4::Position pos);

    void move(dev4::Direction direction);

    SubjectEnum iconToSubject(Icon icon);

    int push(dev4::Position PlayerPos, dev4::Direction direction);

    dev4::Position getPositionAfterPush(dev4::Position player, dev4::Direction dir);

    void applyTransform();

    Icon subjectToIcon(SubjectEnum subjectEnum);

    void sink();

    void kill();

    bool isWin();

    ~BabaIsYou() override;

    void registerObserver(Observer *observer) override;

    void setRules(const RuleManager &rules);

    void setPlayerPos(const std::vector<dev4::Position> &playerPos);

    void setObservers(const std::vector<Observer *> &observers);

    void unregisterObserver() override;

    void notifyObservers() override;


    std::string convertionString(Element element);

    void undo();
    void redo();
    void movePlayer(dev4::Direction direction);

    BabaIsYou(const BabaIsYou& other);
    void revertTo(BabaIsYou* babaIsYou);

    void saveLevel(const int nombre) const;

};

#endif //PROJET_BABA_IS_YOU_BABAISYOU_H
