//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_LEVELLOADER_H
#define PROJET_BABA_IS_YOU_LEVELLOADER_H

#include "board.h"

class LevelLoader{
private:
    Board board;
public:
    LevelLoader(int level);

public:

    const Board &getBoard() const;

    void setBoard(const Board &newBoard);
    void browseLevel(int numberLevel);


};


#endif //PROJET_BABA_IS_YOU_LEVELLOADER_H
