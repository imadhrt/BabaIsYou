//
// Created by elhar on 25-03-23.
//

#include <map>
#include "../../headerFile/model/board.h"

Element Board::convertionEnum(std::string strFile){
    static std::map<std::string, Element> elemMap{

            {"grass", Element(Materials(Icon::GRASS_ICON))},
            {"wall", Element(Materials(Icon::WALL_ICON))},
            {"lava", Element(Materials(Icon::LAVA_ICON))},
            {"baba", Element(Materials(Icon::BABA_ICON))},
            {"rock", Element(Materials(Icon::ROCK_ICON))},
            {"bone", Element(Materials(Icon::BONE_ICON))},
            {"goop", Element(Materials(Icon::GOOP_ICON))},
            {"metal", Element(Materials(Icon::METAL_ICON))},
            {"text_grass", Element(Words(Subject(SubjectEnum::GRASS)))},
            {"text_wall", Element(Words(Subject(SubjectEnum::WALL)))},
            {"text_lava", Element(Words(Subject(SubjectEnum::LAVA)))},
            {"text_baba", Element(Words(Subject(SubjectEnum::BABA)))},
            {"text_rock", Element(Words(Subject(SubjectEnum::ROCK)))},
            {"text_bone", Element(Words(Subject(SubjectEnum::BONE)))},
            {"text_goop", Element(Words(Subject(SubjectEnum::GOOP)))},
            {"text_metal", Element(Words(Subject(SubjectEnum::METAL)))},
            {"win", Element(Words(Complement(ComplementEnum::WIN)))},
            {"kill", Element(Words(Complement(ComplementEnum::KILL)))},
            {"stop", Element(Words(Complement(ComplementEnum::STOP)))},
            {"you", Element(Words(Complement(ComplementEnum::YOU)))},
            {"push", Element(Words(Complement(ComplementEnum::PUSH)))},
            {"best", Element(Words(Complement(ComplementEnum::BEST)))},
            {"sink", Element(Words(Complement(ComplementEnum::SINK)))},
            {"empty", Element(Materials(Icon::EMPTY_ICON))},
            {"is", Element(Words(Operator(OperatorEnum::IS)))},
            {"text_flag", Element(Words(Subject(SubjectEnum::FLAG)))},
            {"flag", Element(Materials(Icon::FLAG_ICON))}
    };

    auto i = elemMap.find(strFile);

    if(i != elemMap.end()){

        return i -> second;
    } else {
        return Element(Materials(Icon::EMPTY_ICON));
    }
}

Board::Board(LevelLoader file) : file(file){

    board.resize(file.getWidth(), std::vector<Tiles>(file.getHeight()));

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(i).size(); ++j) {
            Materials mat = Materials(Icon::EMPTY_ICON);
            std::vector<Element> el {Element(mat)};
            dev4::Position pos {j, i};
            Tiles emptyTiles{el,pos};
            board.at(i).at(j) = emptyTiles;
        }
    }

    for (int i = 0; i < file.getVecPAire().size(); ++i) {
        Materials mat = Materials(Icon::EMPTY_ICON);
        std::vector<Element> el { Element(mat), convertionEnum(file.getVecPAire().at(i).first)};
        dev4::Position pos {file.getVecPAire().at(i).second.x(),file.getVecPAire().at(i).second.y()};
        Tiles tile {el, pos};
        board.at(pos.x()).at(pos.y()) = tile;
    }
//pos.x et pos.y
}



std::vector<std::vector<Tiles>> Board::getBoard() {
    return board;
}

void Board::setElement(dev4::Position newPosition, Element element) {
    if(!contains(newPosition)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    board[newPosition.x()][newPosition.y()].addElement(element);

}

Tiles Board::getTiles(dev4::Position position) {
    if(!contains(position)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    return board.at(position.x()).at(position.y());
}

bool Board::contains(dev4::Position position) {
    return position.x()>=0 && position.x()<=board.size()-1 && position.y()>=0 && position.y()<=board[0].size();
}

Element Board::dropElement(dev4::Position position) {
    if(!contains(position)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    return board[position.x()][position.y()].removeLastElement();
}

const LevelLoader &Board::getFile() const {
    return file;
}
