//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/operator.h"

Operator::Operator(OperatorEnum newOperatorEnum) : operatorEnum(newOperatorEnum) {}
OperatorEnum Operator::getOperatorEnum() const {
    return operatorEnum;
}

void Operator::setOperatorEnum(OperatorEnum newOperatorEnum) {
    Operator::operatorEnum = newOperatorEnum;
}