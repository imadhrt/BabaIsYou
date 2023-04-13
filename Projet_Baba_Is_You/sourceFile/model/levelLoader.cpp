//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/levelLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


void LevelLoader::browseLevel(int numberLevel) {

    std::ifstream fichier("../sourceFile/level/level_"  + std::to_string(numberLevel) + ".txt") ;

    std::string str ;
    int dir;
    int x,y ;

    if (fichier.is_open()) {
        std::string ligne;

        std::getline(fichier, ligne);
        std::istringstream lgn(ligne);
        lgn >> height >> width ;

        while (std::getline(fichier, ligne)) {
            std::istringstream lgn(ligne);
            lgn >> str >> x >> y >> dir;
            dev4::Position pos {x, y};
            std::pair<std::string, dev4::Position> paire {str, pos};
            vecPAire.push_back(paire);
        }
        fichier.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
}

LevelLoader::LevelLoader(int level) {
    browseLevel(level);
}

int LevelLoader::getWidth() const {
    return width;
}

int LevelLoader::getHeight() const {
    return height;
}

const vector<std::pair<std::string, dev4::Position>> &LevelLoader::getVecPAire() const {
    return vecPAire;
}
