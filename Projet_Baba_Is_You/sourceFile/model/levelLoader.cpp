//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/levelLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Parcours le niveau spécifié et stocke les informations de chaque objet dans un vecteur.
 *
 * @param numberLevel Le numéro du niveau à parcourir.
 */
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
            lgn >> str >> y >> x >> dir;
            dev4::Position pos {x, y};
            std::pair<std::string, dev4::Position> paire {str, pos};
            vecPAire.push_back(paire);
        }
        fichier.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
}

/**
 * Parcours le niveau spécifié et stocke les informations de chaque objet dans un vecteur.
 *
 * @param numberLevel Le numéro du niveau à parcourir.
 */
void LevelLoader::browseLevelSaved(int levelSaved){

    std::ifstream fichier("../sourceFile/levelSaved/"+ to_string(levelSaved) +".txt") ;

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
            lgn >> str >> y >> x >> dir;
            dev4::Position pos {x, y};
            std::pair<std::string, dev4::Position> paire {str, pos};
            vecPAire.push_back(paire);
        }
        fichier.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
}


/**
 *  Constructeur de la classe LevelLoader.
 *
 * @param level Le numéro du niveau à charger.
 */
LevelLoader::LevelLoader(int level, bool save):
    level(level),
    save(save)
{
    if(save){
        browseLevelSaved(level);
    }else{
        browseLevel(level);
    }
}


bool LevelLoader::getSave() const{
    return save;
}

/**
 *  Accesseur pour le numéro de niveau chargé.
 *
 * @return Le numéro de niveau chargé.
 */
int LevelLoader::getLevel() const {
    return level;
}
/**
 * Mutateur pour le numéro de niveau chargé.
 *
 * @param level Le nouveau numéro de niveau à charger.
 */

void LevelLoader::setLevel(int level) {
    LevelLoader::level = level;
}
/**
 *  Accesseur pour la largeur du niveau.
 *
 * @return La largeur du niveau.
 */
int LevelLoader::getWidth() const {
    return width;
}
/**
 *  Accesseur pour la hauteur du niveau.
 *
 * @return La hauteur du niveau.
 */
int LevelLoader::getHeight() const {
    return height;
}
/**
 *  Accesseur pour le vecteur contenant les informations de chaque objet du niveau.
 *
 * @return Le vecteur contenant les informations de chaque objet du niveau.
 */
const vector<std::pair<std::string, dev4::Position>> &LevelLoader::getVecPAire() const {
    return vecPAire;
}

