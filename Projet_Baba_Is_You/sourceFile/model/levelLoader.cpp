//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/levelLoader.h"
#include "../../headerFile/model/words.h"
#include "../../headerFile/model/subject.h"
#include "../../headerFile/model/materials.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const Board &LevelLoader::getBoard() const {
    return board;
}

void LevelLoader::setBoard(const Board &newBoard) {
    LevelLoader::board = newBoard;
}

void LevelLoader::browseLevel(int numberLevel) {

    std::stringstream chemin;
    chemin << "../sourceFile/level/level_" << numberLevel << ".txt";
    std::string fichierString = chemin.str();

    std::ifstream fichier(fichierString);

    int i = 0;
    if (fichier.is_open()) {
        std::string ligneFichier;
        while (std::getline(fichier, ligneFichier)) {
            std::string element;
            std::vector<std::string> elementLigne;
            istringstream decompose(ligneFichier);
            while (decompose >> element) {
                elementLigne.push_back(element);
            }
            if (i == 0) {
                board=Board(stoi(elementLigne.at(0)),stoi(elementLigne.at(1)));
                i++;
            } else {
//                if (elementLigne.size() == 3) {
//
//
//                } else {
//
//
//                }
   dev4::Position position=dev4::Position(stoi(elementLigne.at(1)),stoi(elementLigne.at(2)));
   std::vector<Element> listeElement;
          if(elementLigne.at(0)=="text_wall"){
              Words word=Subject(SubjectEnum::WALL);
              listeElement.push_back(word);
              board.setTile(position, Tiles(listeElement));
          }else if(elementLigne.at(0)=="wall"){
              Materials materials=Materials(Icon::WALL_ICON);
              listeElement.push_back(materials);
              board.setTile(position, Tiles(listeElement));
          }



//                i++;
            }
            elementLigne.clear();
        }
        fichier.close();
    }


}

LevelLoader::LevelLoader(int level, Board board) : board(board) {
    browseLevel(level);
}
