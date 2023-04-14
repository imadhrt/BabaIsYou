//
// Created by elhar on 25-03-23.
//

#ifndef PROJET_BABA_IS_YOU_RULEMANAGER_H
#define PROJET_BABA_IS_YOU_RULEMANAGER_H

#include <vector>
#include "rule.h"

class RuleManager{
private:
    std::vector<Rule> listOfRules;

public:
    void addRule(Rule rule);
    void clearRule();

};




#endif //PROJET_BABA_IS_YOU_RULEMANAGER_H
