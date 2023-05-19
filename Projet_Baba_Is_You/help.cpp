#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    QIcon iconSave("../icon/saveIcon.png");
    ui->saveIcon->setPixmap(iconSave.pixmap(QSize(32, 32)));
    QIcon iconMove("../icon/moveIcon.jpeg");
    ui->moveIcon->setPixmap(iconMove.pixmap(QSize(32, 32)));
    QIcon iconUndo("../icon/undoIcon.png");
    ui->undoIcon->setPixmap(iconUndo.pixmap(QSize(32, 32)));
    QIcon iconRedo("../icon/redoIcon.png");
    ui->redoIcon->setPixmap(iconRedo.pixmap(QSize(32, 32)));
    QIcon iconRestart("../icon/restartIcon.png");
    ui->restartIcon->setPixmap(iconRestart.pixmap(QSize(32, 32)));
    QIcon iconExit("../icon/exitIcon.png");
    ui->exitIcon->setPixmap(iconExit.pixmap(QSize(32, 32)));

}

Help::~Help()
{
    delete ui;
}

