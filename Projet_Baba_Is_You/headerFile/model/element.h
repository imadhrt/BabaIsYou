//
// Created by Mamoun benmassaoud on 14/03/2023.
//

#ifndef PROJET_BABA_IS_YOU_ELEMENT_H
#define PROJET_BABA_IS_YOU_ELEMENT_H

#include <ostream>

class Element {
private:
    Element *element;
public:
    explicit Element(Element *element);

    Element();

    virtual ~Element();


    void setElement(Element *element);

    Element& operator=(const Element &other);


    Element getElement() const;
};

Element::Element(Element *element) : element(element) {}

Element::Element() : element(nullptr) {}

Element::~Element() {
    delete element;
}

Element Element::getElement() const {
    return *this->element;
}

void Element::setElement(Element *element) {
    Element::element = element;
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


#endif //PROJET_BABA_IS_YOU_ELEMENT_H
