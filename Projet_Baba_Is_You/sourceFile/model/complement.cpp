//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/complement.h"

Complement::Complement( ComplementEnum newComplementEnum) : complementEnum(newComplementEnum) {}

ComplementEnum Complement::getComplementEnum() const {
    return complementEnum;
}

void Complement::setComplementEnum(ComplementEnum newComplementEnum) {
    Complement::complementEnum = newComplementEnum;
}
