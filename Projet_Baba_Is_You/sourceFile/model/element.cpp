//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/element.h"

Element::Element()  {}
Element::~Element() {}

Element::Element(Materials mat) : words(), mat(mat) {}

Element::Element(Words words) : words(words) {}
