//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/rule.h"

Rule::~Rule() {

}

Rule::Rule(Subject subject,Operator operator_,Complement complement) : subject(subject),operator_(operator_),complement(complement) {}

