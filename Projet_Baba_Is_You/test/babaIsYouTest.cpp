#include "catch/catch.hpp"
#include "../headerFile/model/babaisyou.h"
#include <vector>
#include <iostream>
using namespace std ;

int levelNumber = 0;
LevelLoader levelLoader(levelNumber);
Board board(levelLoader);
BabaIsYou babaIsYou(&board);



TEST_CASE( "Test move up when it is possible" ) {

   dev4::Position pos=babaIsYou.getPlayerPos().at(0);

    auto posPlayer=babaIsYou.getBoard()->getTiles(pos);
    babaIsYou.move(dev4::Direction::RIGHT);

    REQUIRE(babaIsYou.getBoard()->getTiles(pos.nextPos(dev4::Direction::RIGHT))==babaIsYou.getBoard()->getTiles(pos));



}
TEST_CASE( "Test move rock to the right" ) {
    babaIsYou.getBoard()->setElement(dev4::Position(0,0), Element(Materials(Icon::ROCK_ICON)));

    dev4::Position pos = dev4::Position(0,0);
    babaIsYou.move(dev4::Direction::RIGHT);

    REQUIRE(babaIsYou.getBoard()->getTiles(pos.nextPos(dev4::Direction::RIGHT)).getListElement().back().getMat()->getIcon()== Icon::ROCK_ICON);
     REQUIRE(babaIsYou.getBoard()->getTiles(pos).getListElement().size()==1);
}



TEST_CASE( "Test if rule added " ) {
    babaIsYou.getBoard()->setElement(dev4::Position(1,1), Element(Words(Subject(SubjectEnum::ROCK))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,2), Element(Words(Operator(OperatorEnum::IS))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,3), Element(Words(Complement(ComplementEnum::KILL))));
    babaIsYou.findAndAddRules();





    REQUIRE( babaIsYou.getBoard()->getTiles(dev4::Position(1,1)).getListElement().back().getWords()->getSubject().isKill());

}

TEST_CASE( "Test if rule remove " ) {
    babaIsYou.getBoard()->setElement(dev4::Position(1,1), Element(Words(Subject(SubjectEnum::ROCK))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,2), Element(Words(Operator(OperatorEnum::IS))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,3), Element(Words(Complement(ComplementEnum::KILL))));
    babaIsYou.findAndAddRules();

    babaIsYou.getBoard()->getTiles(dev4::Position(1,2)).removeLastElement();


babaIsYou.findAndAddRules();



    REQUIRE( !babaIsYou.getBoard()->getTiles(dev4::Position(1,1)).getListElement().back().getWords()->getSubject().isKill());

}

TEST_CASE( "Test baba is rock transform " ) {
    babaIsYou.getBoard()->setElement(dev4::Position(1,1), Element(Words(Subject(SubjectEnum::BABA))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,2), Element(Words(Operator(OperatorEnum::IS))));
    babaIsYou.getBoard()->setElement(dev4::Position(1,3), Element(Words(Subject(SubjectEnum::ROCK))));
    babaIsYou.findAndAddRules();
    babaIsYou.applyTransform();
    babaIsYou.getBoard()->getTiles(babaIsYou.getPlayerPos().at(0)).getListElement().back().getMat()->getIcon();



    REQUIRE(  babaIsYou.getBoard()->getTiles(babaIsYou.getPlayerPos().at(0)).getListElement().back().getMat()->getIcon()==Icon::ROCK_ICON);

}


TEST_CASE( "Test broke the regle Baba is you" ) {
    babaIsYou.getBoard()->dropElement(dev4::Position(4,12));


    auto posPLayerBeforeMove=babaIsYou.getPlayerPos().at(0);
           babaIsYou.move(dev4::Direction::RIGHT);




    REQUIRE( posPLayerBeforeMove.x()==babaIsYou.getPlayerPos().at(0).x() );
    REQUIRE(posPLayerBeforeMove.y()==babaIsYou.getPlayerPos().at(0).y());
}

TEST_CASE( "Test next level and win " ) {
    babaIsYou.getBoard()->setElement(dev4::Position(0,0), Element(Materials(Icon::BABA_ICON)));
    babaIsYou.getBoard()->setElement(dev4::Position(0,1), Element(Materials(Icon::FLAG_ICON)));
    babaIsYou.move(dev4::Direction::RIGHT);




    REQUIRE( babaIsYou.getBoard()->getFile().getLevel()==1);
}
