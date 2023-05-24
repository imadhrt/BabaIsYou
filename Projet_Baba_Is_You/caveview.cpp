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
#include "chooselevel.h"
#include "win.h"
#include "help.h"

#include <QCloseEvent>

CaveView::CaveView(int levelNumber, BabaIsYou babaIsYou, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaveView),
    levelNumber(levelNumber),
    babaIsYou(babaIsYou),
    gridLayout(new QGridLayout(this)),
    isFirstDisplay(true)
{
   //babaIsYou.registerObserver(this);
    previousBoardState = babaIsYou.getBoard()->getBoard();
    ui->setupUi(this);
    initMenu();
    initBoard();
    displayBoard();
    this->adjustSize();
    this->setFixedSize(550,550);

}

CaveView::~CaveView()
{

    delete ui;

}

void CaveView::initMenu(){
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuFile = new QMenu("File");

    QString styleSheet = "QMenuBar { color: white; }"; // Remplacez "red" par la couleur de votre choix

    // Appliquer la feuille de style au menuBar
    menuBar->setStyleSheet(styleSheet);

    menuBar->addMenu(menuFile);
//   menuFile->setStyleSheet("background-color:white;");



    QAction *actionSave = new QAction( QIcon("../icon2/save.png"),"Save", this);
    QAction *actionReplay = new QAction(QIcon("../icon2/replay.png"), "Replay", this);
    QAction *actionExit = new QAction(QIcon("../icon2/exit.png"), "Exit", this);
    QAction *actionLevel = new QAction(QIcon("../icon2/level.png"), "Choose level", this);
    QAction *actionHelpCommand = new QAction(QIcon("../icon2/help.png"), "Help Command", this);


    menuFile->addAction(actionSave);
    menuFile->addAction(actionReplay);
    menuFile->addAction(actionExit);
    menuFile->addAction(actionLevel);
    menuFile->addAction(actionHelpCommand);

    gridLayout->setMenuBar(menuBar);
    connect(actionSave, &QAction::triggered, this, &CaveView::saveGame);
    connect(actionReplay, &QAction::triggered, this, &CaveView::replay);
    connect(actionExit, &QAction::triggered, this, &CaveView::exit);
    connect(actionLevel, &QAction::triggered, this, &CaveView::chooselevel);
    connect(actionHelpCommand, &QAction::triggered, this, &CaveView::helpCommand);
}

void CaveView::saveGame(){
    SaveLevel *saveLevel = new SaveLevel(babaIsYou);
    saveLevel->show();
}

void CaveView::helpCommand() {
        Help *help = new Help();
        QRect firstWindowGeometry = this->geometry();
        int x = firstWindowGeometry.x() + firstWindowGeometry.width() + 685;
        int y = firstWindowGeometry.y() + 180;
        help->move(x, y);
        help->show();
}



void CaveView::exit(){
    QApplication::quit();
}

void CaveView::replay(){
    babaIsYou.start(babaIsYou.getBoard()->getFile().getLevel(), false);
    babaIsYou.notifyObservers();
    }

void CaveView::chooselevel(){
    close();
    ChooseLevel *chooseLevel = new ChooseLevel();

    chooseLevel->show();
}

void CaveView::initBoard(){
    for (int i = 0; i < babaIsYou.getBoard()->getFile().getHeight(); ++i) {
        for (int j = 0; j < babaIsYou.getBoard()->getFile().getWidth(); ++j) {
             QLabel *imgLabel = new QLabel();
            gridLayout->addWidget(imgLabel,i,j);
        }
    }
}

void CaveView::displayBoard() {
    std::vector<std::vector<Tiles>> currentBoardState = babaIsYou.getBoard()->getBoard();

    if ( !isFirstDisplay && currentBoardState == previousBoardState) {
        return;
    }
    isFirstDisplay=false;
    // Mise à jour de l'état précédent
    previousBoardState = currentBoardState;




    gridLayout->setSpacing(0);

    for (int i = 0; i < babaIsYou.getBoard()->getFile().getHeight(); ++i) {
        for (int j = 0; j < babaIsYou.getBoard()->getFile().getWidth(); ++j) {
                auto element = babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().at(
                    babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().size() - 1);

            QString imgPath;
                if (element.getMat() != nullptr && element.getWords() == nullptr) {
                imgPath = CaveView::toPicsIcon(element.getMat()->getIcon());
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

                auto item = gridLayout->itemAtPosition(i,j);
                if(item){
                    if(QLabel *label = qobject_cast<QLabel*>(item->widget())){
                        QPixmap pixmap(imgPath);

                        int newWitdh = 30;
                        int newHeight = pixmap.height() * newWitdh / pixmap.width();
                        QPixmap scaledPixmap = pixmap.scaled(newWitdh, newHeight, Qt::KeepAspectRatio);

                        label->setPixmap(scaledPixmap);
                    }
                }


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
        saveGame();
        break;

    case Qt::Key_R:
        replay();

        break;

    case Qt::Key_X:
        exit();
        break;

    case Qt::Key_H:
        helpCommand();
        break;

    case Qt::Key_Z:
        babaIsYou.undo();
        return;

    case Qt::Key_Y:
        babaIsYou.redo();
        return;

    default:
        dir = dev4::Direction::NONE;
    }


        babaIsYou.registerObserver(this);
        babaIsYou.movePlayer(dir);






    }




QString CaveView::toPicsIcon(Icon icon)
{
    QString imgPath;

    switch (icon) {
    case Icon::METAL_ICON :
        imgPath = "../sprite/TILE.png";
        break;
    case Icon::FLAG_ICON :
        imgPath = "../sprite/flag.png";
        break;
    case Icon::GRASS_ICON :
        imgPath = "../sprite/grass.png";
        break;
    case Icon:: WALL_ICON:
        imgPath = "../sprite/wall.png";
        break;
    case Icon::LAVA_ICON :
        imgPath = "../sprite/lave.jpg";
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
    case ComplementEnum::KILL :
        imgPath = "../sprite/Text_KILL.png";
        break;
    default:
        imgPath = "../sprite/Text_KILL2.png";
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


void CaveView::update() {
    displayBoard();
    if (babaIsYou.isWin()) {
        int nextLevel = babaIsYou.getBoard()->getFile().getLevel() + 1;
        bool isSave = babaIsYou.getBoard()->getFile().getSave();
        if (nextLevel <= 4 && !isSave) {
                babaIsYou.start(nextLevel, isSave);
                babaIsYou.notifyObservers();
        }else{
                close();
                Win *win = new Win();
                win->show();
        }
    }
}
