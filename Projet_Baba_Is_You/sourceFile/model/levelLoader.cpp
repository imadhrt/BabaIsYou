//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/levelLoader.h"


const Board &LevelLoader::getBoard() const {
    return board;
}

void LevelLoader::setBoard(const Board &newBoard) {
    LevelLoader::board = newBoard;
}

void LevelLoader::browseLevel(int numberLevel) {


}