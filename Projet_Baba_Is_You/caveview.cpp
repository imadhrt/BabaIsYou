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

CaveView::CaveView(int levelNumber, BabaIsYou babaIsYou, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaveView),
    levelNumber(levelNumber),
    babaIsYou(babaIsYou),
    gridLayout(new QGridLayout(this))
{

    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    ui->setupUi(this);
    initMenu();
    displayBoard();
    this->adjustSize();
    this->setFixedSize(580,580);
    helpCommand();
}

CaveView::~CaveView()
{
    delete ui;
}

void CaveView::initMenu(){
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuFile = new QMenu("File");
    menuBar->addMenu(menuFile);


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

bool CaveView::isHelpShown = false;

void CaveView::helpCommand() {
    if (!isHelpShown) {
        Help *help = new Help();
        QRect firstWindowGeometry = this->geometry();
        int x = firstWindowGeometry.x() + firstWindowGeometry.width() + 305; // Ajoute un espace de 10 pixels entre les fenêtres
        int y = firstWindowGeometry.y() + 180;
        help->move(x, y);
        help->show();
        isHelpShown = true;
    }
}



void CaveView::exit(){
    QApplication::quit();
}

void CaveView::replay(){
    babaIsYou.start(babaIsYou.getBoard()->getFile().getLevel(), false);
    displayBoard();
    }

void CaveView::chooselevel(){
    close();
    ChooseLevel *chooseLevel = new ChooseLevel();

    chooseLevel->show();
}



void CaveView::displayBoard() {

    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    gridLayout->setSpacing(0);

    for (int i = 0; i < babaIsYou.getBoard()->getFile().getHeight(); ++i) {
        for (int j = 0; j < babaIsYou.getBoard()->getFile().getWidth(); ++j) {
                auto element = babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().at(
                    babaIsYou.getBoard()->getBoard().at(i).at(j).getListElement().size() - 1);
            QLabel *imgLabel = new QLabel();
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
        std::cout << "d";
        babaIsYou.undo();
        break;

    case Qt::Key_Y:
               babaIsYou.redo();
               std::cout << "d";
               break;

    default:
        dir = dev4::Direction::NONE;
    }

    try {
        babaIsYou.movePlayer(dir);
        displayBoard();
        }catch (std::exception exception){
        }

       if (babaIsYou.isWin()) {
        std::cout << "test";
                int nextLevel = babaIsYou.getBoard()->getFile().getLevel() + 1;

                if (nextLevel <= 4) {
                babaIsYou.start(nextLevel, false);
                displayBoard();
                }else{
                close();
                Win *win = new Win();
                win->show();
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
