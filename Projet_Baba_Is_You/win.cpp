#include "win.h"
#include "ui_win.h"
#include "chooselevel.h"
#include <QKeyEvent>

Win::Win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
    setBackground("../sprite/background.png");
    connect(ui->exitButton, &QPushButton::clicked, this, &Win::exitClicked);
    connect(ui->chooseButton, &QPushButton::clicked, this, &Win::chooseClicked);
}

Win::~Win()
{
    delete ui;
}

void Win::setBackground(const QString& imagePath)
{
    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
}


void Win::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    setBackground("../sprite/background.png");

}

void Win::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);
    if ( event->key() == Qt::Key_Space) {
        close();
        ChooseLevel *chooseLevel = new ChooseLevel();

        chooseLevel->show();
    }
}


void Win::exitClicked(){
    QApplication::quit();
}


void Win::chooseClicked(){
    close();
    ChooseLevel *chooseLevel = new ChooseLevel();

    chooseLevel->show();
}
