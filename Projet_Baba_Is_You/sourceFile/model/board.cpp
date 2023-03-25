//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/board.h"


Board::Board(int height, int width) {
    for (int i = 0; i < height ;++i) {
        for (int j = 0; j < width ; ++j) {
            board.at(i).at(j)=Tiles();

        }
    }

}

std::vector<std::vector<Tiles>> Board::getBoard() {
    return board;
}

void Board::setTile(dev4::Position newPosition, Tiles tiles) {
    if(!contains(newPosition)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    board[newPosition.x()][newPosition.y()]=Tiles();

}

Tiles Board::getTiles(dev4::Position position) {
    if(!contains(position)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    return board.at(position.x()).at(position.y()).getListElement();
}

bool Board::contains(dev4::Position position) {
    return position.x()>=0 && position.x()<=board.size()-1 && position.y()>=0 && position.y()<=board[0].size();
}

void Board::dropTile(dev4::Position position) {
    setTile(position,Tiles());

}
