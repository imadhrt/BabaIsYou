//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_OPERATOR_H
#define PROJET_BABA_IS_YOU_OPERATOR_H

#include "enum.h"

class Operator{
public:
    explicit Operator(OperatorEnum newOperatorEnum);
    Operator()=default;
    OperatorEnum getOperatorEnum() const;

    bool operator==(const Operator &rhs) const;

    bool operator!=(const Operator &rhs) const;

    void setOperatorEnum(OperatorEnum newOperatorEnum);

private :
    OperatorEnum operatorEnum;

};


#endif //PROJET_BABA_IS_YOU_OPERATOR_H
