#include "start.h"
#include "ui_start.h"
#include <iostream>
/*
Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    std::cout << "hello start" << std::endl;
    ui->setupUi(this);
    backgroundPixmap.load("../sprite/Baba_is_youBackGround.jpg");
    setFixedSize(backgroundPixmap.size());
}
*/

#include "start.h"
#include "ui_start.h"
#include <QVBoxLayout>
#include <QWidget>

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    setBackground("C:\\Users\\elhar\\DEV4\\BABAISYOU\\babaisyou-g58132-g58112\\Projet_Baba_Is_You\\sprite\\Baba_is_youBackGround.jpg");
    //setBackground("C:\\Users\\adamj\\OneDrive\\Documents\\CourESI\\DEV4\\dev4-projet\\baba_is_you\\images\\fond_debut.jpg");
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
    setBackground("C:\\Users\\elhar\\DEV4\\BABAISYOU\\babaisyou-g58132-g58112\\Projet_Baba_Is_You\\sprite\\Baba_is_youBackGround.jpg");
    //setBackground("C:\\Users\\adamj\\OneDrive\\Documents\\CourESI\\DEV4\\dev4-projet\\baba_is_you\\images\\fond_debut.jpg");
}

void Start::keyPressEvent(QKeyEvent *event)
{
//    setFocusPolicy(Qt::StrongFocus);
//    if (event->key() == Qt::Key_Space) {
//        Form *f = new Form();
//        f->show();
//        close();
//    }
}

