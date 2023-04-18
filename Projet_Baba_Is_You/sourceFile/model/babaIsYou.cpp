//
// Created by Mamoun benmassaoud on 17/04/2023.
//
#include "../../headerFile/model/babaisyou.h";
#include <algorithm>

BabaIsYou::BabaIsYou(const Board &board) : board(board) {
    findAndAddRules();
}

void BabaIsYou::findAndAddRules() {
    rules.clearRule();

    int height = board.getFile().getHeight();
    int width = board.getFile().getWidth();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto element = board.getBoard().at(i).at(j).getListElement();
            auto lastElement = element.at(board.getBoard().at(i).at(j).getListElement().size() - 1);
            if (lastElement.getWords() != nullptr && &lastElement.getWords()->getOperator() != nullptr) {
                // Check left and right positions
                if (j > 0 && j < width - 1) {
                    auto leftElement = board.getBoard().at(i).at(j - 1).getListElement().at(
                            board.getBoard().at(i).at(j-1).getListElement().size() - 1);
                    auto rightElement = board.getBoard().at(i).at(j + 1).getListElement().at(
                            board.getBoard().at(i).at(j+1).getListElement().size() - 1);
                    if (leftElement.getWords() != nullptr && &leftElement.getWords()->getSubject() != nullptr &&
                        rightElement.getWords() != nullptr && &rightElement.getWords()->getComplement() != nullptr) {
                        rules.addRule(Rule(leftElement.getWords()->getSubject(), lastElement.getWords()->getOperator(),
                                           rightElement.getWords()->getComplement()));
                    }
                }

                if (i > 0 && i < height - 1) {
                    auto topElement = board.getBoard().at(i - 1).at(j).getListElement().at(board.getBoard().at(i-1).at(j).getListElement().size() - 1);
                    auto bottomElement = board.getBoard().at(i + 1).at(j).getListElement().at(board.getBoard().at(i+1).at(j).getListElement().size() - 1);
                    if (topElement.getWords() != nullptr && &topElement.getWords()->getSubject() != nullptr &&
                        bottomElement.getWords() != nullptr && &bottomElement.getWords()->getComplement() != nullptr) {
                        rules.addRule(Rule(topElement.getWords()->getSubject(), lastElement.getWords()->getOperator(), bottomElement.getWords()->getComplement()));
                    }
                }
            }
        }
    }
        setEffetToSubject();
}

void BabaIsYou::setEffetToSubject(){
    for (int i = 0; i < rules.getListOfRules().size(); ++i) {
        ComplementEnum complementEnum = rules.getListOfRules().at(i).getComplement().getComplementEnum();
        const Subject& subject =  rules.getListOfRules().at(i).getSubject();
        Subject& nonConstSubject = const_cast<Subject&>(subject);
        switch (complementEnum) {
            case ComplementEnum::PUSH:
                nonConstSubject.setPush(true);
                break;
            case ComplementEnum::KILL:
                nonConstSubject.setKill(true);
                break;
            case ComplementEnum::SINK:
                nonConstSubject.setSink(true);
                break;
            case ComplementEnum::BEST:
                nonConstSubject.setBest(true);
                break;
            case ComplementEnum::YOU:
                nonConstSubject.setYou(true);
                break;
            case ComplementEnum::WIN:
                nonConstSubject.setWin(true);
                break;
            case ComplementEnum::STOP:
                nonConstSubject.setStop(true);
                break;
        }
    }
}

const Board &BabaIsYou::getBoard() const {
    return board;
}

const RuleManager &BabaIsYou::getRules() const {
    return rules;
}

void BabaIsYou::applyRule(){
    for (int i = 0; i < rules.getListOfRules().size(); ++i) {
        const Subject& subject =  rules.getListOfRules().at(i).getSubject();
        Subject& nonConstSubject = const_cast<Subject&>(subject);

        if(subject.isStop()){

        }
    }
}

const std::vector<dev4::Position> &BabaIsYou::getPlayerPos() const {
    return playerPos;
}

std::vector<dev4::Position> BabaIsYou::getVecPosPlayer(){

    SubjectEnum playerSubject = SubjectEnum::NONE;
    bool found = true;
    for (int i = 0; i < rules.getListOfRules().size() && found; ++i) {
        if(rules.getListOfRules().at(i).getSubject().isYou()){
            playerSubject = rules.getListOfRules().at(i).getSubject().getSubjectEnum();
            found = false;
        }
    }

    Icon icon = Icon::EMPTY_ICON;
    switch (playerSubject) {
        case SubjectEnum::BABA:
            icon = Icon::BABA_ICON;
            break;
        case SubjectEnum::ROCK:
            icon = Icon::ROCK_ICON;
            break;
        case SubjectEnum::FLAG:
            icon = Icon::FLAG_ICON;
            break;
        case SubjectEnum::WALL:
            icon = Icon::WALL_ICON;
            break;
        case SubjectEnum::METAL:
            icon = Icon::METAL_ICON;
            break;
            case SubjectEnum::BONE:
            icon = Icon::BONE_ICON;
            break;
            case SubjectEnum::GRASS:
            icon = Icon::GRASS_ICON;
            break;
            case SubjectEnum::GOOP:
            icon = Icon::GOOP_ICON;
            break;
        case SubjectEnum::LAVA:
            icon = Icon::LAVA_ICON;
            break;
    }

    if(icon == Icon::EMPTY_ICON) {
        return playerPos;
    }

    playerPos.clear();
    for (int i = 0; i < board.getFile().getHeight(); ++i) {
        for (int j = 0; j < board.getFile().getWidth(); ++j) {
            if (contains(board.getBoard().at(i).at(j).getListElement(),icon)) {
                playerPos.push_back(dev4::Position(i,j));
            }
        }
    }

    return playerPos;
}


bool BabaIsYou::contains(const std::vector<Element>& vec, Icon icon) {
    for (int i = 0; i < vec.size(); ++i) {
        if(vec.at(i).getMat() != nullptr && vec.at(i).getMat()->getIcon() == icon){
            return true;
        }
    }
    return false;
}

bool BabaIsYou::isPossibleMove(dev4::Direction dir, dev4::Position pos){
    dev4::Position positionDir (dir);
    if(!board.contains(dev4::Position(pos.x()+positionDir.x(),pos.y()+positionDir.y()))){
        return false;
    }

}
