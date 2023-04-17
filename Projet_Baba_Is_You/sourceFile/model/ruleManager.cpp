//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/ruleManager.h"

void RuleManager::addRule(Rule rule) {
    listOfRules.push_back(rule);
}

void RuleManager::clearRule() {
    listOfRules.clear();
}

const std::vector<Rule> &RuleManager::getListOfRules() const {
    return listOfRules;
}
