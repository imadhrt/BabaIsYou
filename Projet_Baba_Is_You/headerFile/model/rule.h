//
// Created by elhar on 25-03-23.
//

#ifndef PROJET_BABA_IS_YOU_RULE_H
#define PROJET_BABA_IS_YOU_RULE_H

#include "subject.h"
#include "operator.h"
#include "complement.h"

class Rule{
public:


    Rule(Subject subject, Operator operator_, Complement complement);

    virtual ~Rule();


private:
    Subject subject;
    Operator operator_;
    Complement complement;
};




#endif //PROJET_BABA_IS_YOU_RULE_H
