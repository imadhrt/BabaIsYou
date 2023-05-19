#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    QIcon iconSave("../icon2/saveIcon.png");
    ui->saveIcon->setPixmap(iconSave.pixmap(QSize(32, 32)));
    QIcon iconMove("../icon2/moveIcon.jpeg");
    ui->moveIcon->setPixmap(iconMove.pixmap(QSize(32, 32)));
    QIcon iconUndo("../icon2/undoIcon.png");
    ui->undoIcon->setPixmap(iconUndo.pixmap(QSize(32, 32)));
    QIcon iconRedo("../icon2/redoIcon.png");
    ui->redoIcon->setPixmap(iconRedo.pixmap(QSize(32, 32)));
    QIcon iconRestart("../icon2/restartIcon.png");
    ui->restartIcon->setPixmap(iconRestart.pixmap(QSize(32, 32)));
    QIcon iconExit("../icon2/exitIcon.png");
    ui->exitIcon->setPixmap(iconExit.pixmap(QSize(32, 32)));

}

Help::~Help()
{
    delete ui;
}

