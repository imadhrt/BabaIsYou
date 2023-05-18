#include <iostream>
#include <QApplication>
#include "../../headerFile/model/board.h"
#include "../../headerFile/model/babaisyou.h"
#include "../../headerFile/controller/controller.h"
#include "../../headerFile/view/view.h"
#include "../../mainwindow.h"
#include "../../start.h"
using namespace std;
using namespace dev4;

/*
int main() {

    int levelNumber = 0;
    LevelLoader levelLoader(levelNumber, false);
    Board board(levelLoader);
    BabaIsYou babaIsYou(&board);
    BabaIsYouView gameView(&babaIsYou);
    BabaIsYouController gameController(&babaIsYou,&gameView);
     gameController.start();

    return 0;
}*/


int main (int argc , char* argv []){
    QApplication application(argc , argv ) ;

    Start s ;
    s.show();

    /*
    MainWindow myWindow;
    myWindow.show ( ) ;
    */
    return  application.exec();


}




