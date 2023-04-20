//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/operator.h"
#include "../../headerFile/model/words.h"

/**

Constructeur de la classe Operator.
@param newOperatorEnum L'énumération représentant le type d'opérateur à associer à l'objet Operator.
*/
Operator::Operator(OperatorEnum newOperatorEnum) : operatorEnum(newOperatorEnum) {}
/**

Getter pour récupérer l'énumération représentant le type d'opérateur associé à l'objet Operator.
@return L'énumération représentant le type d'opérateur associé à l'objet Operator.
*/
OperatorEnum Operator::getOperatorEnum() const {
    return operatorEnum;
}
/**

Setter pour définir l'énumération représentant le type d'opérateur associé à l'objet Operator.
@param newOperatorEnum La nouvelle énumération représentant le type d'opérateur à associer à l'objet Operator.
*/
void Operator::setOperatorEnum(OperatorEnum newOperatorEnum) {
    Operator::operatorEnum = newOperatorEnum;
}
/**

Opérateur de comparaison d'égalité entre deux objets Operator.
@param rhs L'objet Operator à comparer avec l'objet courant.
@throws Aucune exception n'est levée par cette méthode.
@return Booléen indiquant si les deux objets sont égaux en comparant leur énumération d'opérateur.
*/
bool Operator::operator==(const Operator &rhs) const {
    return operatorEnum == rhs.operatorEnum;
}
/**

Opérateur de comparaison de non-égalité entre deux objets Operator.
@param rhs L'objet Operator à comparer avec l'objet courant.
@throws Aucune exception n'est levée par cette méthode.
@return Booléen indiquant si les deux objets sont différents en comparant leur énumération d'opérateur.
*/
bool Operator::operator!=(const Operator &rhs) const {
    return !(rhs == *this);
}