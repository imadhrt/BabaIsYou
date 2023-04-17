//
// Created by Mamoun benmassaoud on 14/03/2023.
//

#ifndef PROJET_BABA_IS_YOU_ELEMENT_H
#define PROJET_BABA_IS_YOU_ELEMENT_H

#include <ostream>
#include "subject.h"
#include "operator.h"
#include "complement.h"
#include "materials.h"
#include "words.h"

class Element{
private:
    Materials* mat;
    Words* words;
public:
    Element()=default;

    Element(Materials mat, Words words);

    explicit Element(Words words);

    Materials *getMat() const;

    Words *getWords() const;

    bool operator==(const Element &rhs) const;

    bool operator!=(const Element &rhs) const;

    explicit Element(Materials mat);

    virtual ~Element();


};


#endif //PROJET_BABA_IS_YOU_ELEMENT_H
