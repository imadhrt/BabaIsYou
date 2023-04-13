//
// Created by elhar on 25-03-23.
//

#include <map>
#include "../../headerFile/model/board.h"
#include "../../headerFile/model/enum.h"
#include "../../headerFile/model/materials.h"
#include "../../headerFile/model/words.h"


Board::Board(LevelLoader file) : file(file){

    board.resize(file.getWidth(), std::vector<Tiles>(file.getHeight()));
    Materials mat = Materials(Icon::EMPTY_ICON);
    std::vector<Element> el {mat};
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(i).size(); ++j) {
            dev4::Position pos {j, i};
            Tiles emptyTiles{el,pos};
            board.at(i).at(j) = emptyTiles;
        }
    }

    for (int i = 0; i < file.getVecPAire().size(); ++i) {
        el.push_back(convertionEnum(file.getVecPAire().at(i).first));
        dev4::Position pos {file.getVecPAire().at(i).second.x(),file.getVecPAire().at(i).second.y()};
        Tiles tile {el, pos};
        board.at(file.getVecPAire().at(i).second.y()).at(file.getVecPAire().at(i).second.x()) = tile;
    }

}
Element convertionEnum(std::string strFile){
    static std::map<std::string, Element> elemMap{

            {"grass", Materials(Icon::GRASS_ICON)},
            {"wall", Materials(Icon::WALL_ICON)},
            {"lava", Materials(Icon::LAVA_ICON)},
            {"baba", Materials(Icon::BABA_ICON)},
            {"rock", Materials(Icon::ROCK_ICON)},
            {"bone", Materials(Icon::BONE_ICON)},
            {"goop", Materials(Icon::GOOP_ICON)},
            {"metal", Materials(Icon::METAL_ICON)},
            {"text_grass", Words(Subject(SubjectEnum::GRASS))},
            {"text_wall", Words(Subject(SubjectEnum::WALL))},
            {"text_lava", Words(Subject(SubjectEnum::LAVA))},
            {"text_baba", Words(Subject(SubjectEnum::BABA))},
            {"text_rock", Words(Subject(SubjectEnum::ROCK))},
            {"text_bone", Words(Subject(SubjectEnum::BONE))},
            {"text_goop", Words(Subject(SubjectEnum::GOOP))},
            {"text_metal", Words(Subject(SubjectEnum::METAL))},
            {"win", Words(Complement(ComplementEnum::WIN))},
            {"kill", Words(Complement(ComplementEnum::KILL))},
            {"stop", Words(Complement(ComplementEnum::STOP))},
            {"you", Words(Complement(ComplementEnum::YOU))},
            {"push", Words(Complement(ComplementEnum::PUSH))},
            {"best", Words(Complement(ComplementEnum::BEST))},
            {"sink", Words(Complement(ComplementEnum::SINK))},
            {"empty", Materials(Icon::EMPTY_ICON)},
            {"is", Words(Operator(OperatorEnum::IS))},
            {"text_flag", Words(Subject(SubjectEnum::FLAG))},
            {"flag", Materials(Icon::FLAG_ICON)}
    };

    auto i = elemMap.find(strFile);

    if(i != elemMap.end()){

        return i -> second;
    } else {
        return Materials(Icon::EMPTY_ICON);
    }
}

std::vector<std::vector<Tiles>> Board::getBoard() {
    return board;
}

void Board::setTile(dev4::Position newPosition, Tiles tiles) {
    if(!contains(newPosition)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    board[newPosition.x()][newPosition.y()]=tiles;

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

void Board::dropTile(dev4::Position position) {
    setTile(position, Tiles());
}
