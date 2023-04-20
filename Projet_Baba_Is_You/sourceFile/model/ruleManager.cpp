//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/ruleManager.h"

/**
Méthode pour ajouter une règle à la liste des règles.
@param rule La règle à ajouter à la liste.
*/
void RuleManager::addRule(Rule rule) {
    listOfRules.push_back(rule);
}
/**

Méthode pour effacer toutes les règles de la liste des règles
*/
void RuleManager::clearRule() {
    listOfRules.clear();
}

/**

Méthode pour récupérer la liste des règles.
@return La liste des règles.
*/
const std::vector<Rule> &RuleManager::getListOfRules() const {
    return listOfRules;
}
