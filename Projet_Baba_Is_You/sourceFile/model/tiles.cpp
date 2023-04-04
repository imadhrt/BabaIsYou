//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/tiles.h"

Tiles::Tiles(const std::vector<Element> &liste): listElement(liste) {}

Tiles::~Tiles() {
    listElement.clear();
}

const std::vector<Element> &Tiles::getListElement() const {
    return listElement;
}