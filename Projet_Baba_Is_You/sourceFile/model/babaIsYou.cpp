
#include <map>
#include <fstream>
#include <iostream>
#include "../../headerFile/model/babaisyou.h"
#include "../../headerFile/model/moveCommand.h"

/**

Constructeur de la classe BabaIsYou.
@param board le plateau de jeu
*/
BabaIsYou::BabaIsYou(Board *board) : board(board) {
    managerCommand = ManagerCommand();
    findAndAddRules();
    getVecPosPlayer();
}

/**

Démarre une partie avec le niveau spécifié.
Si le niveau est entre 0 et 4 inclusivement, charge le plateau de jeu correspondant
et met à jour les règles du jeu. Trouve également la position initiale du joueur.
@param level le niveau de jeu choisi
*/
void BabaIsYou::start(int level,bool isSave) {
    if(level >=0){
        LevelLoader levelLoader(level,isSave);
        setBoard(new Board(levelLoader));
        findAndAddRules();
        getVecPosPlayer();
    }
}


/**
 * Met à jour les règles du jeu en fonction des éléments présents sur le plateau de jeu.
 */

void BabaIsYou::findAndAddRules() {
    rules.clearRule();

    int height = board->getFile().getHeight();
    int width = board->getFile().getWidth();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto element = board->getBoard().at(i).at(j).getListElement();
            auto lastElement = element.at(board->getBoard().at(i).at(j).getListElement().size() - 1);
            if (lastElement.getWords() != nullptr && &lastElement.getWords()->getOperator() != nullptr) {
                if (j > 0 && j < width - 1) {
                    auto leftElement = board->getBoard().at(i).at(j - 1).getListElement().at(
                            board->getBoard().at(i).at(j-1).getListElement().size() - 1);
                    auto rightElement = board->getBoard().at(i).at(j + 1).getListElement().at(
                            board->getBoard().at(i).at(j+1).getListElement().size() - 1);
                    if (leftElement.getWords() != nullptr && &leftElement.getWords()->getSubject() != nullptr &&
                        rightElement.getWords() != nullptr && &rightElement.getWords()->getComplement() != nullptr) {
                        rules.addRule(Rule(leftElement.getWords()->getSubject(), lastElement.getWords()->getOperator(),
                                           rightElement.getWords()->getComplement()));
                    }
                }

                if (i > 0 && i < height - 1) {
                    auto topElement = board->getBoard().at(i - 1).at(j).getListElement().at(board->getBoard().at(i-1).at(j).getListElement().size() - 1);
                    auto bottomElement = board->getBoard().at(i + 1).at(j).getListElement().at(board->getBoard().at(i+1).at(j).getListElement().size() - 1);
                    if (topElement.getWords() != nullptr && &topElement.getWords()->getSubject() != nullptr &&
                        bottomElement.getWords() != nullptr && &bottomElement.getWords()->getComplement() != nullptr) {
                        rules.addRule(Rule(topElement.getWords()->getSubject(), lastElement.getWords()->getOperator(), bottomElement.getWords()->getComplement()));
                    }
                }
            }
        }
    }
        setEffetToSubject();
}
/**

Applique les effets des compléments aux sujets correspondants.
*/
void BabaIsYou::setEffetToSubject(){
    for (int i = 0; i < rules.getListOfRules().size(); ++i) {
        ComplementEnum complementEnum = rules.getListOfRules().at(i).getComplement().getComplementEnum();
        const Subject& subject =  rules.getListOfRules().at(i).getSubject();
        Subject& nonConstSubject = const_cast<Subject&>(subject);
        switch (complementEnum) {
            case ComplementEnum::PUSH:
                nonConstSubject.setPush(true);
                break;
            case ComplementEnum::KILL:
                nonConstSubject.setKill(true);
                break;
            case ComplementEnum::SINK:
                nonConstSubject.setSink(true);
                break;
            case ComplementEnum::BEST:
                nonConstSubject.setBest(true);
                break;
            case ComplementEnum::YOU:
                nonConstSubject.setYou(true);
                break;
            case ComplementEnum::WIN:
                nonConstSubject.setWin(true);
                break;
            case ComplementEnum::STOP:
                nonConstSubject.setStop(true);
                break;
        }
    }
}
/**
 * Accesseur récupère la liste de règle.
 * @return la liste
 */

const RuleManager &BabaIsYou::getRules() const {
    return rules;
}
/**
 * Accesseur récupères toutes les positions du player.
 * @return les/la position(s) du players
 */
const std::vector<dev4::Position> &BabaIsYou::getPlayerPos() const {
    return playerPos;
}
/**
 * Chercher toutes les positions du player.
 * @return toutes les positions où le player se trouve
 */
std::vector<dev4::Position> BabaIsYou::getVecPosPlayer(){

    SubjectEnum playerSubject = SubjectEnum::NONE;
    bool found = true;
    for (int i = 0; i < rules.getListOfRules().size() && found; ++i) {
        if(rules.getListOfRules().at(i).getSubject().isYou()){
            playerSubject = rules.getListOfRules().at(i).getSubject().getSubjectEnum();
            found = false;
        }
    }

    Icon icon = Icon::EMPTY_ICON;
    switch (playerSubject) {
        case SubjectEnum::BABA:
            icon = Icon::BABA_ICON;
            break;
        case SubjectEnum::ROCK:
            icon = Icon::ROCK_ICON;
            break;
        case SubjectEnum::FLAG:
            icon = Icon::FLAG_ICON;
            break;
        case SubjectEnum::WALL:
            icon = Icon::WALL_ICON;
            break;
        case SubjectEnum::METAL:
            icon = Icon::METAL_ICON;
            break;
            case SubjectEnum::BONE:
            icon = Icon::BONE_ICON;
            break;
            case SubjectEnum::GRASS:
            icon = Icon::GRASS_ICON;
            break;
            case SubjectEnum::GOOP:
            icon = Icon::GOOP_ICON;
            break;
        case SubjectEnum::LAVA:
            icon = Icon::LAVA_ICON;
            break;
    }

    if(icon == Icon::EMPTY_ICON) {
        return playerPos;
    }

    playerPos.clear();
    for (int i = 0; i < board->getFile().getHeight(); ++i) {
        for (int j = 0; j < board->getFile().getWidth(); ++j) {
            if (contains(board->getBoard().at(i).at(j).getListElement(),icon)) {
                playerPos.push_back(dev4::Position(i,j));
            }
        }
    }

    return playerPos;
}

/**

Vérifie si un vecteur d'éléments contient une icône donnée.
@param vec le vecteur d'éléments à vérifier
@param icon l'icône à chercher
@return true si le vecteur d'éléments contient l'icône donnée, false sinon
*/
bool BabaIsYou::contains(const std::vector<Element>& vec, Icon icon) {
    for (int i = 0; i < vec.size(); ++i) {
        if(vec.at(i).getMat() != nullptr && vec.at(i).getMat()->getIcon() == icon){
            return true;
        }
    }
    return false;
}

/**
 * Converti une enum subject en enum complement
 * @param subjectEnum est un subject enum
 * @return l'icon du sujet
 */
Icon BabaIsYou::subjectToIcon(SubjectEnum subjectEnum){
    Icon icon = Icon::EMPTY_ICON;
    switch (subjectEnum) {
        case SubjectEnum::BABA:
            icon = Icon::BABA_ICON;
            break;
        case SubjectEnum::ROCK:
            icon = Icon::ROCK_ICON;
            break;
        case SubjectEnum::FLAG:
            icon = Icon::FLAG_ICON;
            break;
        case SubjectEnum::WALL:
            icon = Icon::WALL_ICON;
            break;
        case SubjectEnum::METAL:
            icon = Icon::METAL_ICON;
            break;
        case SubjectEnum::BONE:
            icon = Icon::BONE_ICON;
            break;
        case SubjectEnum::GRASS:
            icon = Icon::GRASS_ICON;
            break;
        case SubjectEnum::GOOP:
            icon = Icon::GOOP_ICON;
            break;
        case SubjectEnum::LAVA:
            icon = Icon::LAVA_ICON;
            break;
            case SubjectEnum::WATER:
            icon = Icon::WATER_ICON;
            break;
    }
    return icon;
}
/**
 * Convertit un Icon en SubjectEnum.
 * @param icon L'Icon à convertir.
 * @return Le SubjectEnum correspondant à l'Icon.
 */
SubjectEnum BabaIsYou::iconToSubject(Icon icon){
    SubjectEnum subject = SubjectEnum::NONE;
    switch (icon) {
        case Icon::BABA_ICON:
            subject = SubjectEnum::BABA;
            break;
        case Icon::ROCK_ICON:
            subject = SubjectEnum::ROCK;
            break;
        case Icon::FLAG_ICON:
            subject = SubjectEnum::FLAG;
            break;
        case Icon::WALL_ICON:
            subject = SubjectEnum::WALL;
            break;
        case Icon::METAL_ICON:
            subject = SubjectEnum::METAL;
            break;
        case Icon::BONE_ICON:
            subject = SubjectEnum::BONE;
            break;
            case Icon::WATER_ICON:
            subject = SubjectEnum::WATER;
            break;
        case Icon::GRASS_ICON:
            subject = SubjectEnum::GRASS;
            break;
        case Icon::GOOP_ICON:
            subject = SubjectEnum::GOOP;
            break;
        case Icon::LAVA_ICON:
            subject = SubjectEnum::LAVA;
            break;
        default:
            break;
    }
    return subject;
}
/**
 * Verifie si le mouvement est valide ou pas.
 * @param dir est la direction qu'on veut y aller
 * @param pos est la position
 * @return true si le mouvement est possible sinon false
 */
bool BabaIsYou::isPossibleMove(dev4::Direction dir, dev4::Position pos){
    if(!board->contains(pos.nextPos(dir))){
        return false;
    }

    auto listElements = board->getBoard().at(pos.nextPos(dir).x()).at(pos.nextPos(dir).y()).getListElement();

    SubjectEnum subjectEnum;
    for (int i = 0; i < listElements.size(); ++i) {
        if(listElements.at(i).getMat() != nullptr && listElements.at(i).getMat()->getIcon() != Icon::EMPTY_ICON && listElements.at(i).getWords() == nullptr){
            subjectEnum = iconToSubject(listElements.at(i).getMat()->getIcon());
            for (int j = 0; j < rules.getListOfRules().size(); ++j) {
                if(rules.getListOfRules().at(j).getSubject().getSubjectEnum() == subjectEnum && rules.getListOfRules().at(j).getSubject().isStop()){
                    return false;
                }
            }
        }
    }

    return true;
}
/**

Cette méthode permet de compter le nombre d'éléments qui peuvent être poussés dans une direction donnée à partir d'une position de joueur donnée.
@param posPlayer La position du joueur à partir de laquelle les éléments seront poussés.
@param dir La direction dans laquelle les éléments seront poussés.
@return Le nombre d'éléments qui peuvent être poussés dans la direction donnée à partir de la position du joueur donnée.
*/
int BabaIsYou::push(dev4::Position posPlayer, dev4::Direction dir)
{
    int cpt{0};
            for (int i = 0; i < rules.getListOfRules().size(); ++i) {
                while (board->getTiles(posPlayer.nextPos(dir)).getListElement().at(board->getTiles(posPlayer.nextPos(dir)).getListElement().size() - 1).getMat() != nullptr
                && rules.getListOfRules().at(i).getSubject().getSubjectEnum() == iconToSubject(board->getTiles(posPlayer.nextPos(dir)).getListElement().at(board->getTiles(posPlayer.nextPos(dir)).getListElement().size() - 1).getMat()->getIcon())
                && rules.getListOfRules().at(i).getSubject().isPush()
                ||board->getTiles(posPlayer.nextPos(dir)).getListElement().at(board->getTiles(posPlayer.nextPos(dir)).getListElement().size() - 1).getWords() != nullptr) {
                    ++cpt;
                    posPlayer = posPlayer.nextPos(dir);
                }
                }
    return cpt;
}
/**

 Calcule la position du joueur après avoir effectué une action de poussée dans la direction donnée.
 Elle utilise la fonction push() pour déterminer combien de rochers peuvent être poussés dans la direction donnée,
 puis calcule la position finale du joueur en fonction de cela.

@param player La position actuelle du joueur.

@param dir La direction dans laquelle le joueur effectue l'action de poussée.

@return La position du joueur après avoir effectué l'action de poussée dans la direction donnée.
*/
dev4::Position BabaIsYou::getPositionAfterPush(dev4::Position player, dev4::Direction dir){
    int lastRock{push(player, dir)};

    switch (dir) {
        case dev4::Direction::LEFT:
            return dev4::Position{player.x(), player.y() - lastRock};
        case dev4::Direction::RIGHT :
            return dev4::Position  {player.x(), player.y()+lastRock};
        case dev4::Direction::DOWN:
            return dev4::Position {player.x()+lastRock, player.y()};
        case dev4::Direction::UP :
            return dev4::Position {player.x()-lastRock, player.y()};
    }
}
/**
 * Cherche les elements qui ont un mot composé d'un opérateur et de deux sujets adjacents.
 * Si les sujets sont valide alors on transforme le sujet en un autre sujet.
 */
void BabaIsYou::applyTransform() {
    int height = board->getFile().getHeight();
    int width = board->getFile().getWidth();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto element = board->getBoard().at(i).at(j).getListElement();
            auto lastElement = element.at(board->getBoard().at(i).at(j).getListElement().size() - 1);
            if (lastElement.getWords() != nullptr && &lastElement.getWords()->getOperator() != nullptr) {
                if (j > 0 && j < width - 1) {
                    auto leftElement = board->getBoard().at(i).at(j - 1).getListElement().at(
                            board->getBoard().at(i).at(j-1).getListElement().size() - 1);
                    auto rightElement = board->getBoard().at(i).at(j + 1).getListElement().at(
                            board->getBoard().at(i).at(j+1).getListElement().size() - 1);
                    if (leftElement.getWords() != nullptr && &leftElement.getWords()->getSubject() != nullptr &&
                        rightElement.getWords() != nullptr && &rightElement.getWords()->getSubject() != nullptr) {
                        transform(leftElement.getWords()->getSubject(),rightElement.getWords()->getSubject());
                    }
                }

                if (i > 0 && i < height - 1) {
                    auto topElement = board->getBoard().at(i - 1).at(j).getListElement().at(board->getBoard().at(i-1).at(j).getListElement().size() - 1);
                    auto bottomElement = board->getBoard().at(i + 1).at(j).getListElement().at(board->getBoard().at(i+1).at(j).getListElement().size() - 1);
                    if (topElement.getWords() != nullptr && &topElement.getWords()->getSubject() != nullptr &&
                        bottomElement.getWords() != nullptr && &bottomElement.getWords()->getSubject() != nullptr) {
                        transform(topElement.getWords()->getSubject(),bottomElement.getWords()->getSubject());
                        }
                    }
                }
            }
        }
}

/**
 * transforme un sujet en un autre sujet
 * @param firstSubject
 * @param secondSubject
 */
void BabaIsYou::transform(Subject firstSubject, Subject secondSubject){
    int height = board->getFile().getHeight();
    int width = board->getFile().getWidth();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Icon leftIcon = subjectToIcon(firstSubject.getSubjectEnum());
            Icon rightIcon = subjectToIcon(secondSubject.getSubjectEnum());
            auto listElement = board->getBoard().at(i).at(j).getListElement();
            for (int k = 0; k < listElement.size(); ++k) {
                Element element = listElement.at(k);
                if(element.getMat() != nullptr && leftIcon == element.getMat()->getIcon()){
                    element.getMat()->setIcon(rightIcon);
                }
            }
        }
    }
}
/**
vérifier si des éléments doivent être coulés ou tués selon les règles du jeu
 */
void BabaIsYou::sinkAndKill(){
    int height = board->getFile().getHeight();
    int width = board->getFile().getWidth();
    auto rulesList = rules.getListOfRules();

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            dev4::Position posOfTile(i, j);
            auto elementsList = board->getTiles(posOfTile).getListElement();
            int size = elementsList.size();
            if (size > 1 && elementsList.at(1).getMat() != nullptr) {
                auto icon = elementsList.at(1).getMat()->getIcon();
                for (auto& rule : rulesList) {
                    if (rule.getSubject().getSubjectEnum() == iconToSubject(icon)
                        && (rule.getSubject().isSink() || rule.getSubject().isKill())) {
                        while (size > 2) {
                            board->dropElement(posOfTile);
                            size--;
                        }
                    }
                }
            }
        }
    }
}
/**
 * Methode qui permet de faire le mouvement .
 * @param direction est une dirction.
 */
void BabaIsYou::move(dev4::Direction direction) {
    playerPos = getVecPosPlayer();
    for (int i = 0; i < playerPos.size(); ++i) {
        dev4::Position player = playerPos.at(i);

        if (isPossibleMove(direction, getPositionAfterPush(player, direction))) {
            for (int i = 0; i < rules.getListOfRules().size(); ++i) {

                auto getSubjectOfRules = rules.getListOfRules().at(i).getSubject();

                auto nextPosOfPlayer = board->getTiles(player.nextPos(direction));
                auto elementsNextpos = nextPosOfPlayer.getListElement();
                auto lastElementOfNextPos = elementsNextpos.at(elementsNextpos.size() - 1);

                auto nextPosNextPosOfPlayer = board->getTiles(player.nextPos(direction).nextPos(direction));
                auto elementsNextposNextPos = nextPosNextPosOfPlayer.getListElement();
                auto lastElementOfNextPosNextpos = elementsNextpos.at(elementsNextpos.size() - 1);

                auto playerToMove = board->getTiles(player).getListElement().at(board->getTiles(player).getListElement().size() - 1);


                if (lastElementOfNextPos.getMat() != nullptr && (lastElementOfNextPos.getMat()->getIcon() == Icon::METAL_ICON
                                                                 || getSubjectOfRules.getSubjectEnum() == iconToSubject(lastElementOfNextPos.getMat()->getIcon()))
                    && !getSubjectOfRules.isPush() && lastElementOfNextPos.getWords() == nullptr){
                    board->setElement(player.nextPos(direction),playerToMove);
                    board->dropElement(player);
                    break;
                }else if (lastElementOfNextPosNextpos.getMat() != nullptr && (lastElementOfNextPosNextpos.getMat()->getIcon() == Icon::METAL_ICON
                                                                              || getSubjectOfRules.getSubjectEnum() == iconToSubject(lastElementOfNextPosNextpos.getMat()->getIcon()))
                          && (!getSubjectOfRules.isPush() && !getSubjectOfRules.isStop()) && lastElementOfNextPos.getWords() == nullptr){

                    board->setElement(player.nextPos(direction).nextPos(direction),lastElementOfNextPos);
                    board->dropElement(player.nextPos(direction));

                    board->setElement(player.nextPos(direction),playerToMove);
                    board->dropElement(player);
                    break;

                }else {
                    int cpt {push(player, direction)};

                    switch (direction) {
                        case dev4::Direction::UP:
                            while (cpt > 0){
                                dev4::Position rock = dev4::Position(player.x()-cpt,player.y());
                                auto elementToPush = board->getTiles(rock).getListElement().at(board->getTiles(rock).getListElement().size() - 1);
                                board->setElement(rock.nextPos(direction), elementToPush);
                                board->dropElement(rock);
                                --cpt;
                            }
                            break;

                        case dev4::Direction::DOWN:
                            while (cpt > 0){
                                dev4::Position rock = dev4::Position(player.x()+cpt,player.y());
                                auto elementToPush = board->getTiles(rock).getListElement().at(board->getTiles(rock).getListElement().size()-1);
                                board->setElement(rock.nextPos(direction), elementToPush);
                                board->dropElement(rock);
                                --cpt;
                            }
                            break;

                        case dev4::Direction::RIGHT:
                            while (cpt > 0) {
                                dev4::Position rock = dev4::Position(player.x(),player.y()+cpt);
                                auto elementToPush = board->getTiles(rock).getListElement().at(board->getTiles(rock).getListElement().size()-1);
                                board->setElement(rock.nextPos(direction), elementToPush);
                                board->dropElement(rock);
                                --cpt;
                            }
                            break;

                        case dev4::Direction::LEFT:
                            while (cpt > 0){
                                dev4::Position rock = dev4::Position(player.x(),player.y()-cpt);
                                auto elementToPush = board->getTiles(rock).getListElement().at(board->getTiles(rock).getListElement().size()-1);
                                board->setElement(rock.nextPos(direction), elementToPush);
                                board->dropElement(rock);
                                --cpt;
                            }
                            break;
                    }

                    board->setElement(player.nextPos(direction), playerToMove);
                    board->dropElement(player);
                    break;
                }
            }
        }
    }

    sinkAndKill();
    findAndAddRules();
    applyTransform();
    getVecPosPlayer();

    notifyObservers();
}
/**
 * Methode qui vérifie si on a gagné le niveau ou pas.
 * @return true si on a gagné le niveau sinon non
 */
bool BabaIsYou::isWin() {
    for (const dev4::Position player : playerPos) {
        Tiles tile = board->getTiles(player);
        for (const Element& element : tile.getListElement()) {
             Materials* materials = element.getMat();
            if (materials != nullptr) {
                auto icon = materials->getIcon();
                for (auto& rule : rules.getListOfRules()) {
                    if (rule.getSubject().getSubjectEnum() == iconToSubject(icon)
                        && (rule.getSubject().isWin())){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
/**
 * Accesseur du board en pointeur
 * @return un pointeur vers le board
 */
Board *BabaIsYou::getBoard() const {
    return board;
}
/**
 * Mutateur du board
 * @param board est un board
 */
void BabaIsYou::setBoard(Board *board) {
    BabaIsYou::board = board;
}
/**
 * Déstructeur de la classe BababIsYou
 */
BabaIsYou::~BabaIsYou() {

}

void BabaIsYou::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void BabaIsYou::unregisterObserver() {
    observers.pop_back();
}

void BabaIsYou::notifyObservers() {
    for(const auto observer : observers){
        observer->update();
    }
}

void BabaIsYou::undo() {
    managerCommand.undo();
}

void BabaIsYou::redo() {
    managerCommand.redo();
}

void BabaIsYou::movePlayer(dev4::Direction direction){
    managerCommand.addCommand(new MoveCommand(this,direction));
}

void BabaIsYou::setRules(const RuleManager &rules) {
    BabaIsYou::rules = rules;
}

void BabaIsYou::setPlayerPos(const std::vector<dev4::Position> &playerPos) {
    BabaIsYou::playerPos = playerPos;
}

void BabaIsYou::setObservers(const std::vector<Observer *> &observers) {
    BabaIsYou::observers = observers;
}

BabaIsYou::BabaIsYou(const BabaIsYou& other)
        :
          rules(other.rules),
          observers(other.observers),
          managerCommand(other.managerCommand),
          playerPos(other.playerPos)
{
    board = new Board(other.board);
    getVecPosPlayer();
}

 void BabaIsYou::revertTo(BabaIsYou* babaIsYou) {
     playerPos = babaIsYou->getPlayerPos();
     board = new Board(babaIsYou->board);
     observers = babaIsYou->observers;
     rules = babaIsYou->rules;

    notifyObservers();
}


void BabaIsYou::saveLevel(const int nombre) const {
    std::ofstream outputFile("../sourceFile/levelSaved/"  + std::to_string(nombre) + ".txt");
    if (!outputFile.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier " << nombre << std::endl;
        return;
    }

    outputFile << board->getFile().getHeight() << " " << board->getFile().getWidth() << std::endl;

    for (int y = 0; y < board->getFile().getHeight(); y++) {
        for (int x = 0; x < board->getFile().getWidth(); x++) {
            for (int i = 1; i < board->getBoard().at(x).at(y).getListElement().size(); ++i) {
                Element element = board->getBoard().at(x).at(y).getListElement().at(i);
                if (element.getWords() != nullptr) {
                    if(&element.getWords()->getSubject() != nullptr) {
                        std::string elementStr = toStringS(element.getWords()->getSubject().getSubjectEnum());
                        outputFile << elementStr << " " << y << " " << x << std::endl;
                    }else if(&element.getWords()->getComplement() != nullptr) {
                        std::string elementStr = toStringComplement(element.getWords()->getComplement().getComplementEnum());
                        outputFile << elementStr << " " << y << " " << x << std::endl;
                    }else{
                        std::string elementStr = toStringOperator(element.getWords()->getOperator().getOperatorEnum());
                        outputFile << elementStr << " " << y << " " << x << std::endl;
                    }
                }else {
                    if (element.getMat() != nullptr && element.getMat()->getIcon() != Icon::EMPTY_ICON) {
                        std::string elementStr = toStringI(element.getMat()->getIcon());
                        outputFile << elementStr << " " << y << " " << x << std::endl;
                    }
                }
            }
        }
    }

    outputFile.close();
}