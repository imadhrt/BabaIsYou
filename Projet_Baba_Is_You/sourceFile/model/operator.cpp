//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/operator.h"
#include "../../headerFile/model/words.h"

Operator::Operator(OperatorEnum newOperatorEnum) : operatorEnum(newOperatorEnum) {}
OperatorEnum Operator::getOperatorEnum() const {
    return operatorEnum;
}

void Operator::setOperatorEnum(OperatorEnum newOperatorEnum) {
    Operator::operatorEnum = newOperatorEnum;
}