//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/rule.h"

/**

Destructeur de la classe Rule.
*/
Rule::~Rule() {
}

/**

Méthode pour récupérer le sujet de la règle.
@return Le sujet de la règle.
*/
const Subject &Rule::getSubject() const {
    return subject;
}
/**

Méthode pour récupérer l'opérateur de la règle.
@return L'opérateur de la règle.
*/
const Operator &Rule::getOperator() const {
    return operator_;
}
/**

Méthode pour récupérer le complément de la règle.
@return Le complément de la règle.
*/
const Complement &Rule::getComplement() const {
    return complement;
}
/**

Constructeur qui crée une règle.
@param subject Le sujet associé à la règle.
@param operator_ L'opérateur associé à la règle.
@param complement Le complément associé à la règle.
*/
Rule::Rule(const Subject &subject, const Operator &operator_, const Complement &complement) : subject(subject),
                                                                                              operator_(operator_),
                                                                                              complement(complement) {}