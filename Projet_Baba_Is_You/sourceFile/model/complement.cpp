//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/complement.h"
/**
 * Constructeur de la classe Complement.
 *
 * @param newComplementEnum L'enumération de complément associée à cette instance.
 */
Complement::Complement( ComplementEnum newComplementEnum) : complementEnum(newComplementEnum) {}
/**
 * Accesseur pour l'enumération de complément associée à cette instance.
 *
 * @return L'enumération de complément associée à cette instance.
 */
ComplementEnum Complement::getComplementEnum() const {
    return complementEnum;
}
/**
 * Mutateur pour l'enumération de complément associée à cette instance.
 *
 * @param newComplementEnum La nouvelle enumération de complément à attribuer à cette instance.
 */
void Complement::setComplementEnum(ComplementEnum newComplementEnum) {
    Complement::complementEnum = newComplementEnum;
}
/**
 * Opérateur d'égalité pour la classe Complement.
 *
 * @param rhs L'autre instance de Complement à comparer.
 * @return true si les instances sont égales, sinon false.
 */
bool Complement::operator==(const Complement &rhs) const {
    return complementEnum == rhs.complementEnum;
}
/**
 * Opérateur de différence pour la classe Complement.
 *
 * @param rhs L'autre instance de Complement à comparer.
 * @return true si les instances sont différentes, sinon false.
 */
bool Complement::operator!=(const Complement &rhs) const {
    return !(rhs == *this);
}
