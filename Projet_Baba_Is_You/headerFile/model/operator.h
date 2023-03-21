//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_OPERATOR_H
#define PROJET_BABA_IS_YOU_OPERATOR_H

#include "enum.h"
#include "words.h"

class Operator: public Words{
public:
    explicit Operator(OperatorEnum operatorEnum);

    OperatorEnum getOperatorEnum() const;

    void setOperatorEnum(OperatorEnum operatorEnum);

private :
    OperatorEnum operatorEnum;

};

Operator::Operator(OperatorEnum operatorEnum) : operatorEnum(operatorEnum) {}

OperatorEnum Operator::getOperatorEnum() const {
    return operatorEnum;
}

void Operator::setOperatorEnum(OperatorEnum operatorEnum) {
    Operator::operatorEnum = operatorEnum;
}

#endif //PROJET_BABA_IS_YOU_OPERATOR_H
