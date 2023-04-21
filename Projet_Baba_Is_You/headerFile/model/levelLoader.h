//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_LEVELLOADER_H
#define PROJET_BABA_IS_YOU_LEVELLOADER_H

#include <vector>
#include <string>
#include "position.h"

class LevelLoader{
private:
    int width;
    int height;
    std::vector<std::pair<std::string, dev4::Position>> vecPAire;

    int level;

    std::string stringLevel;
public:
    LevelLoader(int level);


    void browseLevel(int numberLevel);

    int getWidth() const;

    int getHeight() const;

    const std::vector<std::pair<std::string, dev4::Position>> &getVecPAire() const;

    int getLevel() const;

    void setLevel(int level);
    void browseLevelSaved(int levelSaved);
};


#endif //PROJET_BABA_IS_YOU_LEVELLOADER_H
