//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_WORDS_H
#define PROJET_BABA_IS_YOU_WORDS_H

#include "element.h"
#include "operator.h"
#include "subject.h"
#include "complement.h"

class Words: public Element{
private:
    Subject subject_;
    Operator operator_;
    Complement complement_;

public:
    Words(Subject subject);
    Words(Operator op);
    Words(Complement complement);

    Words();
};


#endif //PROJET_BABA_IS_YOU_WORDS_H
