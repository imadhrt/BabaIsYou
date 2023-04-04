//
// Created by elhar on 25-03-23.
//

#ifndef PROJET_BABA_IS_YOU_RULE_H
#define PROJET_BABA_IS_YOU_RULE_H

#include "subject.h"

class Rule{
public:


    Rule(SubjectEnum subjectEnum, OperatorEnum operatorEnum, ComplementEnum complementEnum, bool isYou, bool isKil,
         bool isPush, bool isStop, bool isWin);
    void defineRule();

    virtual ~Rule();

    bool operator==(const Rule &rhs) const;

    bool operator!=(const Rule &rhs) const;

private:
    SubjectEnum subjectEnum;
    OperatorEnum operatorEnum;
    ComplementEnum complementEnum;
    bool isYou;
    bool isKil;
    bool isPush;
    bool isStop;
    bool isWin;



};




#endif //PROJET_BABA_IS_YOU_RULE_H
