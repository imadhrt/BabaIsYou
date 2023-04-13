//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/element.h"


Element::~Element() {}


Element::Element(Materials mat, Words words) : mat(new Materials(mat)), words(new Words(words)) {}

Element::Element(Materials mat) : mat(new Materials(mat)),words(nullptr) {}

Element::Element(Words words) : words(new Words(words)),mat(nullptr) {}
