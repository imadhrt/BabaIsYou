//
// Created by elhar on 25-03-23.
//

#ifndef PROJET_BABA_IS_YOU_RULE_H
#define PROJET_BABA_IS_YOU_RULE_H

#include "subject.h"
#include "operator.h"
#include "complement.h"

class Rule{
private:
    Subject subject;
    Operator operator_;
    Complement complement;
public:

    Rule(const Subject &subject, const Operator &operator_, const Complement &complement);

    virtual ~Rule();

    const Subject &getSubject() const;

    const Operator &getOperator() const;

    const Complement &getComplement() const;
};




#endif //PROJET_BABA_IS_YOU_RULE_H
