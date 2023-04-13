//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/words.h"

Words::Words(Subject subject) : subject_(subject){}

Words::Words(Operator op) : operator_(op) {}

Words::Words(Complement complement) : complement_(complement) {}

const Subject &Words::getSubject() const {
    return subject_;
}

const Operator &Words::getOperator() const {
    return operator_;
}

const Complement &Words::getComplement() const {
    return complement_;
}

//Words::Words() : subject_(nullptr), operator_(nullptr), complement_(nullptr) {}




