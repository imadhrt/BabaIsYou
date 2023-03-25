//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/element.h"

Element::Element(Element *newElement) : element(newElement) {}

Element::Element() : element(nullptr) {}

Element::~Element() {
    delete element;
}

Element Element::getElement() const {
    return *this->element;
}

void Element::setElement(Element *newElement) {
    Element::element = newElement;
}

Element &  Element::operator=(const Element &other) {
    if (this != &other) {
        delete element;
        if (other.element != nullptr) {
            element = new Element(*other.element);
        } else {
            element = nullptr;
        }
    }
    return *this;
}