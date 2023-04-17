//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/element.h"


Element::~Element() {}


Element::Element(Materials mat, Words words) : mat(new Materials(mat)), words(new Words(words)) {}

Element::Element(Materials mat) : mat(new Materials(mat)),words(nullptr) {}

Element::Element(Words words) : words(new Words(words)),mat(nullptr) {}

bool Element::operator==(const Element &rhs) const {
    if(words == nullptr && mat != nullptr){
        return mat->getIcon() == rhs.mat->getIcon();
    }else if(words!= nullptr && mat == nullptr){
        return words->getSubject().getSubjectEnum() == rhs.words->getSubject().getSubjectEnum();
    }
}

bool Element::operator!=(const Element &rhs) const {
    return !(rhs == *this);
}


