//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/words.h"

Words::Words(Subject subject) : subject_(new Subject(subject)), operator_(nullptr), complement_(nullptr){}

Words::Words(Operator op) : operator_(new Operator(op)), subject_(nullptr), complement_(nullptr) {}

Words::Words(Complement complement) : complement_(new Complement(complement)), subject_(nullptr), operator_(nullptr) {}

const Subject &Words::getSubject() const {
    return *this->subject_;
}

const Operator &Words::getOperator() const {
    return *this->operator_;
}

const Complement &Words::getComplement() const {
    return *this->complement_;
}

void Words::setSubject(Subject *subject) {
    subject_ = subject;
}




