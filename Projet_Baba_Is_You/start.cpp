
#include <iostream>
#include <QKeyEvent>
#include "start.h"
#include "ui_start.h"
#include <QVBoxLayout>
#include <QWidget>
#include "caveview.h"

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    setBackground("../sprite/background.png");
}

Start::~Start()
{

    delete ui;
}


void Start::setBackground(const QString& imagePath)
{
    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
}


void Start::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    setBackground("../sprite/background.png");

}

void Start::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);
    if ( event->key() == Qt::Key_Space) {

        int levelNumber = 0;
        LevelLoader levelLoader(levelNumber, false);
        Board board(levelLoader);
        BabaIsYou babaIsYou(&board);

        CaveView *caveView = new CaveView(0, babaIsYou);
        close();
        caveView->show();
    }
}

