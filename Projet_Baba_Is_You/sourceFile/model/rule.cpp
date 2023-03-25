//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/rule.h"

Rule::~Rule() {

}

Rule::Rule(SubjectEnum subject, OperatorEnum operatore, ComplementEnum complement, bool you, bool kill,
           bool push, bool stop, bool win) : subjectEnum(subject), operatorEnum(operatore),
                                                   complementEnum(complement), isYou(you), isKil(kill),
                                                   isPush(push), isStop(stop), isWin(win) {}

void Rule::defineRule() {

}

bool Rule::operator==(const Rule &rhs) const {
    return subjectEnum == rhs.subjectEnum &&
           operatorEnum == rhs.operatorEnum &&
           complementEnum == rhs.complementEnum ;
}

bool Rule::operator!=(const Rule &rhs) const {
    return !(rhs == *this);
}

