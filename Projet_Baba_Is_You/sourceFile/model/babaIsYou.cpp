
#include "../../headerFile/model/babaisyou.h"

BabaIsYou::BabaIsYou(Board *board) : board(board) {
    findAndAddRules();
}


void BabaIsYou::start(int level) {
    if(level >=0 && level <= 4){
        LevelLoader levelLoader(level);
        setBoard(new Board(levelLoader));
        findAndAddRules();
        getVecPosPlayer();
    }
}

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



const RuleManager &BabaIsYou::getRules() const {
    return rules;
}

const std::vector<dev4::Position> &BabaIsYou::getPlayerPos() const {
    return playerPos;
}

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


bool BabaIsYou::contains(const std::vector<Element>& vec, Icon icon) {
    for (int i = 0; i < vec.size(); ++i) {
        if(vec.at(i).getMat() != nullptr && vec.at(i).getMat()->getIcon() == icon){
            return true;
        }
    }
    return false;
}

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

Board *BabaIsYou::getBoard() const {
    return board;
}

void BabaIsYou::setBoard(Board *board) {
    BabaIsYou::board = board;
}

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

/*void BabaIsYou::saveLevel1(int numberLevel, Board board) {
    std::ofstream fichier("../sourceFile/level/level_" + std::to_string(numberLevel) + ".txt");

    if (fichier.is_open()) {
        fichier << board.getFile().getHeight() << " " << board.getFile().getWidth() << std::endl;
        for (int i = 0; i < board.getFile().getHeight(); ++i) {
            for (int j = 0; j < board.getFile().getWidth(); ++j) {
                for (int k = 0; k < board.getBoard().at(i).at(j).getListElement().size(); ++k) {
                    auto entity = board.getBoard().at(i).at(j).getListElement().at(k);

                    fichier << entity. << " " << i << " " << j << " " << entity.second.getDirection() << std::endl;
                }

            }
        }
        fichier.close();
    }else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }

    }


std::string BabaIsYou::convertionString(Element element){
    static std::map<Element, std::string> strMap{
            {Element(Materials(Icon::GRASS_ICON)), "grass"},
            {Element(Materials(Icon::WALL_ICON)), "wall"},
            {Element(Materials(Icon::LAVA_ICON)), "lava"},
            {Element(Materials(Icon::BABA_ICON)), "baba"},
            {Element(Materials(Icon::ROCK_ICON)), "rock"},
            {Element(Materials(Icon::BONE_ICON)), "bone"},
            {Element(Materials(Icon::GOOP_ICON)), "goop"},
            {Element(Materials(Icon::METAL_ICON)), "metal"},
            {Element(Materials(Icon::WATER_ICON)), "water"},
            {Element(Words(Subject(SubjectEnum::GRASS))), "text_grass"},
            {Element(Words(Subject(SubjectEnum::WALL))), "text_wall"},
            {Element(Words(Subject(SubjectEnum::LAVA))), "text_lava"},
            {Element(Words(Subject(SubjectEnum::BABA))), "text_baba"},
            {Element(Words(Subject(SubjectEnum::ROCK))), "text_rock"},
            {Element(Words(Subject(SubjectEnum::BONE))), "text_bone"},
            {Element(Words(Subject(SubjectEnum::GOOP))), "text_goop"},
            {Element(Words(Subject(SubjectEnum::METAL))), "text_metal"},
            {Element(Words(Subject(SubjectEnum::WATER))), "text_water"},
            {Element(Words(Complement(ComplementEnum::WIN))), "win"},
            {Element(Words(Complement(ComplementEnum::KILL))), "kill"},
            {Element(Words(Complement(ComplementEnum::STOP))), "stop"},
            {Element(Words(Complement(ComplementEnum::YOU))), "you"},
            {Element(Words(Complement(ComplementEnum::PUSH))), "push"},
            {Element(Words(Complement(ComplementEnum::BEST))), "best"},
            {Element(Words(Complement(ComplementEnum::SINK))), "sink"},
            {Element(Materials(Icon::EMPTY_ICON)), "empty"},
            {Element(Words(Operator(OperatorEnum::IS))), "is"},
            {Element(Words(Subject(SubjectEnum::FLAG))), "text_flag"},
            {Element(Materials(Icon::FLAG_ICON)), "flag"}
    };
    auto i = strMap.find(element);

    if(i != elemMap.end()){

        return i -> second;
    } else {
        return Element(Materials(Icon::EMPTY_ICON));
    }
}

void BabaIsYou::saveLevel(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier " << filename << std::endl;
        return;
    }

    outputFile << board->getFile().getHeight() << " " << board->getFile().getWidth() << std::endl;

    for (int y = 0; y < board->getFile().getHeight(); y++) {
        for (int x = 0; x < board->getFile().getWidth(); x++) {
            for (int i = 0; i < board->getBoard().at(y).at(x).getListElement().size(); ++i) {
                Element element = board->getBoard().at(y).at(x).getListElement().at(i);
                if (element. != ElementType::EMPTY) {
                    std::string elementStr = elemMap.at(element);
                    outputFile << elementStr << " " << x << " " << y << std::endl;
                }
            }


        }
    }

    outputFile.close();
}*/