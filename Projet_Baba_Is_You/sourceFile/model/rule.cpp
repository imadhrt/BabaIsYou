//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/rule.h"

Rule::~Rule() {

}


const Subject &Rule::getSubject() const {
    return subject;
}

const Operator &Rule::getOperator() const {
    return operator_;
}

const Complement &Rule::getComplement() const {
    return complement;
}

Rule::Rule(const Subject &subject, const Operator & operator_, const Complement &complement) : subject(subject),
                                                                                     operator_(operator_),
                                                                                               complement(complement) {}

