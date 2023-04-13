//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_COMPLEMENT_H
#define PROJET_BABA_IS_YOU_COMPLEMENT_H

#include "enum.h"
#include "words.h"

class Complement : public Words{
private:
    ComplementEnum complementEnum;
public:
    explicit Complement( ComplementEnum newComplementEnum);
    Complement()=default;
    ComplementEnum getComplementEnum() const;

    void setComplementEnum(ComplementEnum newComplementEnum);


};



#endif //PROJET_BABA_IS_YOU_COMPLEMENT_H
