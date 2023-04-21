//
// Created by Mamoun benmassaoud on 14/03/2023.
//

#ifndef PROJET_BABA_IS_YOU_BOARD_H
#define PROJET_BABA_IS_YOU_BOARD_H
#include <vector>
#include "position.h"
#include "levelLoader.h"
#include "tiles.h"
class Board {
private:
    std::vector<std::vector<Tiles>> board;
    LevelLoader file;
    Element convertionEnum(std::string strFile);
public:
    Board(LevelLoader& file);
    virtual ~Board();
    std::vector<std::vector<Tiles>> getBoard();
    bool contains(dev4::Position position);
    Element dropElement(dev4::Position position);
    void setElement(dev4::Position newPosition, Element element);
    Tiles getTiles(dev4::Position position);
    const LevelLoader &getFile() const;
    Board(Board* otherBoard);
    std::vector<std::vector<Tiles>> copyBoard(Board* otherBoard);
};

inline std::string toStringSubject(SubjectEnum subjet)
{
    std::string str;

    switch (subjet) {
        case SubjectEnum::FLAG :
            str = "  flag  ";
            break;
        case SubjectEnum::GRASS :
            str = " grass  ";
            break;
        case SubjectEnum::WALL :
            str = "  wall  ";
            break;
        case SubjectEnum::LAVA :
            str = "  lava  ";
            break;
        case SubjectEnum::BABA :
            str = "  baba  ";
            break;
        case SubjectEnum::ROCK :
            str = "  rock  ";
            break;
        case SubjectEnum::BONE:
            str = "  bone  ";
            break;
        case SubjectEnum::GOOP :
            str = "  goop  ";
            break;
        case SubjectEnum::METAL :
            str = " metal  ";
            break;
        case SubjectEnum::WATER :
            str = " water  ";
            break;
        default:
            str="";
    }

    return str;
}

inline std::string toStringComplement(ComplementEnum complementEnum) {

    std::string str;

    switch (complementEnum) {
        case ComplementEnum::WIN :
            str = "  win   ";
            break;
        case ComplementEnum::KILL :
            str = "  kill  ";
            break;
        case ComplementEnum::SINK :
            str = "  sink  ";
            break;
        case ComplementEnum::STOP :
            str = "  stop  ";
            break;
        case ComplementEnum::YOU :
            str = "  you   ";
            break;
        case ComplementEnum::PUSH :
            str = "  push  ";
            break;
        case ComplementEnum::BEST :
            str = "  best  ";
            break;
    }
    return str;
}
inline std::string toStringOperator(OperatorEnum operatorEnum) {

    std::string str;

    switch (operatorEnum) {
        case OperatorEnum::IS :
            str = "   is   ";
            break;
    }
    return str;
}
inline std::string toStringIcon(Icon icon)
{
    std::string str;

    switch (icon) {
        case Icon::FLAG_ICON :
            str = "txtFlag ";
            //str = "\033[31mtxtFlag\033[0m ";
            break;
        case Icon::GRASS_ICON :
            str = "txtGrass";
            break;
        case Icon:: WALL_ICON:
            str = "txtWall ";
            break;
        case Icon::LAVA_ICON :
            str = "txtLava ";
            break;
        case Icon::BABA_ICON :
              str = "txtBaba ";
            break;
        case Icon::ROCK_ICON :
            str = "txtRock ";
            break;
        case Icon::BONE_ICON :
            str = "txtBone ";
            break;
        case Icon::GOOP_ICON :
            str = "txtGoop ";
            break;
        case Icon::METAL_ICON :
            str = "txtMetal";
            break;
        case Icon::EMPTY_ICON :
            str = "--------";
            break;
        case Icon::WATER_ICON :
            str = "txtWater";
            break;
    }

    return str;
}
#endif //PROJET_BABA_IS_YOU_BOARD_H

