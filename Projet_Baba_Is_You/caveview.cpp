#include "caveview.h"
#include "ui_caveview.h"

CaveView::CaveView(int levelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaveView),
    levelNumber(levelNumber),
    babaIsYou(nullptr),
    gridLayout(new QGridLayout(this))
{

    LevelLoader levelLoader(levelNumber, false);
    Board board(levelLoader);
    babaIsYou=BabaIsYou(&board);

    this->adjustSize();

    ui->setupUi(this);
}

CaveView::~CaveView()
{
    delete ui;
}
