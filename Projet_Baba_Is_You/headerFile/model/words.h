//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_WORDS_H
#define PROJET_BABA_IS_YOU_WORDS_H

#include "subject.h"
#include "complement.h"
#include "operator.h"

class Words{
private:
    Subject subject_;
    Operator operator_;
    Complement complement_;

public:
    Words(Subject subject);
    Words(Operator op);
    Words(Complement complement);

    const Subject &getSubject() const;

    const Operator &getOperator() const;

    const Complement &getComplement() const;

    Words();
};


#endif //PROJET_BABA_IS_YOU_WORDS_H
