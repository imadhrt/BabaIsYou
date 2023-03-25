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
    explicit Element(Element *newElement);

    Element();

    virtual ~Element();


    void setElement(Element *newElement);

    Element& operator=(const Element &other);


    Element getElement() const;
};


#endif //PROJET_BABA_IS_YOU_ELEMENT_H
