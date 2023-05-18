#include "caveview.h"
#include "ui_caveview.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "savelevel.h"
#include <QPixmap>
#include "headerFile/model/direction.h"
#include <QKeyEvent>
#include <QLabel>

CaveView::CaveView(int levelNumber, BabaIsYou babaIsYou, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaveView),
    levelNumber(levelNumber),
    babaIsYou(babaIsYou),

    gridLayout(new QGridLayout(this))
{


    ui->setupUi(this);
    initMenu();
    displayBoard();
    this->adjustSize();
}

CaveView::~CaveView()
{
    delete ui;
}

void CaveView::initMenu(){
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuFile = new QMenu("File");
    menuBar->addMenu(menuFile);


    QAction *actionSave = new QAction( "Save", this);
   QAction *actionReplay = new QAction(QIcon("../icon/replay.png"), "Replay", this);
    QAction *actionExit = new QAction(QIcon("../icon/exit.png"), "Exit", this);
    QAction *actionLevel = new QAction(QIcon("../icon/level.png"), "Choose level", this);


    menuFile->addAction(actionSave);
    menuFile->addAction(actionReplay);
    menuFile->addAction(actionExit);
    menuFile->addAction(actionLevel);

    gridLayout->setMenuBar(menuBar);
    connect(actionSave, &QAction::triggered, this, &CaveView::saveGame);
    connect(actionReplay, &QAction::triggered, this, &CaveView::replay);
    connect(actionExit, &QAction::triggered, this, &CaveView::exit);
    connect(actionLevel, &QAction::triggered, this, &CaveView::chooselevel);
}

void CaveView::saveGame(){
    close();
    SaveLevel *saveLevel = new SaveLevel(babaIsYou);
    saveLevel->show();
}

void CaveView::exit(){
    QApplication::quit();
}

void CaveView::replay(){
    babaIsYou.start(babaIsYou.getBoard()->getFile().getLevel(), false);
}

void CaveView::chooselevel(){
    close();
    //ouvrir le form des niveau et show
}



void CaveView::displayBoard() {

    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < babaIsYou.getBoard()->getFile().getHeight(); ++i) {
        for (int j = 0; j < babaIsYou.getBoard()->getFile().getWidth(); ++j) {
                auto element = babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().at(
                    babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().size() - 1);
            QLabel *imgLabel = new QLabel();
            QString imgPath;
                if (element.getMat() != nullptr && element.getWords() == nullptr) {
                imgPath = toPicsIcon(element.getMat()->getIcon());
                } else if (element.getMat() == nullptr && element.getWords() != nullptr) {
                if (&element.getWords()->getSubject() != nullptr && &element.getWords()->getOperator() == nullptr &&
                    &element.getWords()->getComplement() == nullptr) {
                   imgPath = CaveView::toPicsSubject(element.getWords()->getSubject().getSubjectEnum());
                } else if (&element.getWords()->getSubject() == nullptr &&
                           &element.getWords()->getOperator() != nullptr &&
                           &element.getWords()->getComplement() == nullptr) {
                   imgPath = CaveView::toPicsOperator(element.getWords()->getOperator().getOperatorEnum());
                } else {
                    imgPath = CaveView::toPicsComplement(element.getWords()->getComplement().getComplementEnum());
                }
                }
                QPixmap pixmap(imgPath);

                int newWitdh = 30;
                int newHeight = pixmap.height() * newWitdh / pixmap.width();
                QPixmap scaledPixmap = pixmap.scaled(newWitdh, newHeight, Qt::KeepAspectRatio);

                imgLabel->setPixmap(scaledPixmap);
                gridLayout->addWidget(imgLabel,i,j);
        }

    }
}
void CaveView::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);

    dev4::Direction dir = dev4::Direction::NONE;

    switch (event->key()) {
    case Qt::Key_Left:
        dir = dev4::Direction::LEFT;
        break;

    case Qt::Key_Right:
        dir = dev4::Direction::RIGHT;
        break;

    case Qt::Key_Up:
        dir = dev4::Direction::UP;
        break;

    case Qt::Key_Down:
        dir = dev4::Direction::DOWN;
        break;

    case Qt::Key_S:
        if (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier) {
                std::cout << "S" << std::endl;
                saveGame();
        }
        break;

    case Qt::Key_R:
        if (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier) {
                std::cout << "R" << std::endl;
                replay();
        }
        break;

    case Qt::Key_X:
        if (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier) {
                std::cout << "X" << std::endl;
                exit();
        }
        break;
    case Qt::Key_Z:
        if (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier) {
                std::cout << "Z" << std::endl;
               babaIsYou.undo();
        }
        break;
    default:
        dir = dev4::Direction::NONE;
    }

    //std::cout << game.getState() << std::endl ;
    //bool running = true;
    //while (running) {


                try {
                babaIsYou.movePlayer(dir);
                displayBoard();
                }catch (std::exception exception){

                }
         // else {
                //running = false;
      //  }

       if (babaIsYou.isWin()) {
                int nextLevel = babaIsYou.getBoard()->getFile().getLevel() + 1;
                if (nextLevel <= 4) {
                babaIsYou.start(nextLevel, false);
                }
        }
    }



//}


QString CaveView::toPicsIcon(Icon icon)
{
    QString imgPath;

    switch (icon) {
    case Icon::FLAG_ICON :
        imgPath = "../sprite/flag.png";
        //str = "\033[31mtxtFlag\033[0m ";
        break;
    case Icon::GRASS_ICON :
        imgPath = "../sprite/grass.png";
        break;
    case Icon:: WALL_ICON:
        imgPath = "../sprite/wall.png";
        break;
    case Icon::LAVA_ICON :
        imgPath = "../sprite/lava.png";
        break;
    case Icon::BABA_ICON :
        imgPath = "../sprite/baba.png";
        break;
    case Icon::ROCK_ICON :
        imgPath = "../sprite/rock.png";
        break;
    case Icon::BONE_ICON :
        imgPath = "../sprite/bone.png";
        break;
    case Icon::GOOP_ICON :
        imgPath = "../sprite/goop.png";
        break;
    case Icon::EMPTY_ICON :
        imgPath = "../sprite/empty.png";
        break;
    case Icon::WATER_ICON :
        imgPath = "../sprite/water.png";
        break;
    default:
     imgPath = "../sprite/empty.png";
}
    return imgPath;
}

QString CaveView::toPicsSubject(SubjectEnum subjet)
{
    QString imgPath;

    switch (subjet) {
    case SubjectEnum::FLAG :
        imgPath = "../sprite/Text_FLAG.png";
        break;
    case SubjectEnum::GRASS :
        imgPath = "../sprite/Text_GRASS..png";
        break;
    case SubjectEnum::WALL :
        imgPath = "../sprite/Text_WALL.png";
        break;
    case SubjectEnum::LAVA :
        imgPath = "../sprite/Text_LAVA.png";
        break;
    case SubjectEnum::BABA :
        imgPath = "../sprite/Text_BABA.png";
        break;
    case SubjectEnum::ROCK :
        imgPath = "../sprite/Text_ROCK.png";
        break;
    case SubjectEnum::WATER :
        imgPath = "../sprite/Text_WATER.png";
        break;
    default:
        imgPath = "../sprite/empty.png";
    }

    return imgPath;
}

QString CaveView::toPicsComplement(ComplementEnum complementEnum) {

    QString imgPath;

    switch (complementEnum) {
    case ComplementEnum::WIN :
        imgPath = "../sprite/Text_WIN.png";
        break;
    case ComplementEnum::SINK :
        imgPath = "../sprite/Text_SINK.png";
        break;
    case ComplementEnum::STOP :
        imgPath = "../sprite/Text_STOP.png";
        break;
    case ComplementEnum::YOU :
        imgPath = "../sprite/Text_YOU.png";
        break;
    case ComplementEnum::PUSH :
        imgPath = "../sprite/Text_PUSH.png";
        break;

    }
    return imgPath;
}
QString CaveView::toPicsOperator(OperatorEnum operatorEnum) {

    QString imgPath;

    switch (operatorEnum) {
    case OperatorEnum::IS :
        imgPath = "../sprite/Text_IS.png";
        break;
    }
    return imgPath;
}
