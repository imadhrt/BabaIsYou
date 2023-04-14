//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/tiles.h"


Tiles::~Tiles() {
    listElement.clear();
}

const std::vector<Element> &Tiles::getListElement() const {
    return listElement;
}

Tiles::Tiles(const std::vector<Element> &listElement, const dev4::Position &pos) : listElement(listElement), pos(pos) {}

void Tiles::addElement(Element element){
    listElement.push_back(element);
}

Element Tiles::removeLastElement(){
    Element lastElement = listElement.back();
    listElement.pop_back();
    return lastElement;
}
