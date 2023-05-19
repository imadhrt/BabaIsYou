//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_LEVELLOADER_H
#define PROJET_BABA_IS_YOU_LEVELLOADER_H

#include <vector>
#include <string>
#include "position.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

class LevelLoader{
private:
    int width;
    int height;
    std::vector<std::pair<std::string, dev4::Position>> vecPAire;

    int level;
    bool save;
    std::string stringLevel;
public:
    LevelLoader(int level, bool save);


    void browseLevel(int numberLevel);

    int getWidth() const;

    int getHeight() const;

    bool getSave() const;
    const std::vector<std::pair<std::string, dev4::Position>> &getVecPAire() const;

    int getLevel() const;

    void setLevel(int level);
    void browseLevelSaved(int levelSaved);
};

inline std::vector<std::string> listLvl()
{
    std::vector<std::string> filenames;
    //std::string path = "../baba_is_you/ressource";
    std::string path = "./level";



    for(const auto & entry : std::filesystem::directory_iterator(path)){
        if(entry.is_regular_file()){
            filenames.push_back(entry.path().filename().string());
        }
    }

    return filenames;
}

inline void showLvl(){
    for (int i = 0; i < listLvl().size(); ++i) {
        std::cout << listLvl().at(i) << std::endl;
    }
}

inline std::vector<std::string> listLvlSaved()
{
    std::vector<std::string> filenames;
    //std::string path = "../baba_is_you/ressource";
    std::string path = "./levelSaved";



    for(const auto & entry : std::filesystem::directory_iterator(path)){
        if(entry.is_regular_file()){
            filenames.push_back(entry.path().filename().string());
        }
    }

    return filenames;
}

inline void showLvlSaved(){
    for (int i = 0; i < listLvlSaved().size(); ++i) {
        std::cout << listLvlSaved().at(i) << std::endl;
    }
}


#endif //PROJET_BABA_IS_YOU_LEVELLOADER_H
