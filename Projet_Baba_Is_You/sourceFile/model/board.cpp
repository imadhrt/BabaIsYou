//
// Created by elhar on 25-03-23.
//

#include <map>
#include "../../headerFile/model/board.h"
/**
 * Methode permet de convertir un une chaines de caractère en un objec t Element
 * @param strFile est le texte du fichier
 * @return un element correspondant à la chaine .
 */
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
            {"water", Element(Materials(Icon::WATER_ICON))},
            {"text_grass", Element(Words(Subject(SubjectEnum::GRASS)))},
            {"text_wall", Element(Words(Subject(SubjectEnum::WALL)))},
            {"text_lava", Element(Words(Subject(SubjectEnum::LAVA)))},
            {"text_baba", Element(Words(Subject(SubjectEnum::BABA)))},
            {"text_rock", Element(Words(Subject(SubjectEnum::ROCK)))},
            {"text_bone", Element(Words(Subject(SubjectEnum::BONE)))},
            {"text_goop", Element(Words(Subject(SubjectEnum::GOOP)))},
            {"text_metal", Element(Words(Subject(SubjectEnum::METAL)))},
            {"text_water", Element(Words(Subject(SubjectEnum::WATER)))},
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
/**
Constructeur pour la classe "Board".

@param file un objet "LevelLoader" utilisé pour initialiser le tableau "board"
*/
Board::Board(LevelLoader& file) : file(file){

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
        dev4::Position pos {file.getVecPAire().at(i).second.x(),file.getVecPAire().at(i).second.y()};
        if(board.at(pos.x()).at(pos.y()).getListElement().size() < 2) {
            Materials mat = Materials(Icon::EMPTY_ICON);
            std::vector<Element> el { Element(mat), convertionEnum(file.getVecPAire().at(i).first)};
            Tiles tile {el, pos};
            board.at(pos.x()).at(pos.y()) = tile;
        } else{
            board.at(pos.x()).at(pos.y()).addElement(convertionEnum(file.getVecPAire().at(i).first));
        }

    }

}


/**
Getter pour le tableau "board".
@return le tableau "board" de la classe "Board".
*/
std::vector<std::vector<Tiles>> Board::getBoard() {
    return board;
}
/**

Définit un nouvel élément à la position donnée en paramètre.
@param newPosition une nouvelle position.
@param element un nouvel élément.
*/
void Board::setElement(dev4::Position newPosition, Element element) {
    if(!contains(newPosition)){
        throw std::invalid_argument("La position n' est pas dans le board setelement");
    }
    board[newPosition.x()][newPosition.y()].addElement(element);

}

bool Board::isValidPosition(const dev4::Position& pos) const {
    int height = getFile().getHeight();
    int width = getFile().getWidth();

    return (pos.x() >= 0 && pos.x() < height && pos.y() >= 0 && pos.y() < width);
}

/**
Getter pour l'objet "Tiles" se trouvant à la position donnée en paramètre.
@param position une position.
@return l'objet "Tiles" se trouvant à la position donnée en paramètre.
*/
Tiles Board::getTiles(dev4::Position position) {
    if(!contains(position)){
        throw std::invalid_argument("La position n' est pas dans le board fettiles");
    }
    return board.at(position.x()).at(position.y());
}
/**
Vérifie si la position donnée en paramètre est contenue dans le tableau "board".
@param position une position à vérifier.
@return true si la position donnée en paramètre est contenue dans le tableau "board", false sinon.
*/
bool Board::contains(dev4::Position position) {
    return position.x() >= 0 && position.x() < board.size() && position.y() >= 0 && position.y() < board[0].size();
}
/**
Supprime l'élément se trouvant à la position donnée en paramètre et le retourne.
@param position une position à supprimer.
@return l'élément se trouvant à la position donnée en paramètre.
*/
Element Board::dropElement(dev4::Position position) {
    if(!contains(position)){
        throw std::invalid_argument("La position n' est pas dans le board");
    }
    return board[position.x()][position.y()].removeLastElement();
}
/**

Getter pour l'objet "LevelLoader" utilisé pour initialiser le tableau "board" de la classe "Board".
@return une référence constante à l'objet "LevelLoader".
*/
const LevelLoader &Board::getFile() const {
    return file;
}
/**
Destructeur pour la classe "Board".
Libère la mémoire occupée par l'objet "Board".
*/
Board::~Board() {

}

/**
 * Constructeur par copie pour la classe "Board".
 * @param otherBoard le "Board" à copier.
 */
Board::Board(Board* otherBoard) : file(otherBoard->file) {
   board = copyBoard(otherBoard);
}

std::vector<std::vector<Tiles>> Board::copyBoard(Board* otherBoard) {
    board.resize(file.getWidth(), std::vector<Tiles>(file.getHeight()));

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.at(i).size(); ++j) {
            board.at(i).at(j) = otherBoard->getTiles(dev4::Position(i, j));
        }
    }
    return board;
}
