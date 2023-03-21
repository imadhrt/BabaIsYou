//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_COMPLEMENT_H
#define PROJET_BABA_IS_YOU_COMPLEMENT_H

#include "enum.h"
#include "words.h"

class Complement : public Words{
public:
    Complement(Words *words, ComplementEnum complementEnum);

    ComplementEnum getComplementEnum() const;

    void setComplementEnum(ComplementEnum complementEnum);

private:
     ComplementEnum complementEnum;
};

Complement::Complement(Words *words, ComplementEnum complementEnum) : Words(words), complementEnum(complementEnum) {}

ComplementEnum Complement::getComplementEnum() const {
    return complementEnum;
}

void Complement::setComplementEnum(ComplementEnum complementEnum) {
    Complement::complementEnum = complementEnum;
}

#endif //PROJET_BABA_IS_YOU_COMPLEMENT_H
