//
// Created by elhar on 25-03-23.
//
#include "../../headerFile/model/element.h"

/**
 *  Destructeur de la classe Element.
 */
Element::~Element() {}
/**
* Constructeur de la classe Element prenant en entrée un words et un materials.
*
* @param mat La matière associée à l'élément.
* @param words Les mots associés à l'élément.
*/

Element::Element(Materials mat, Words words) : mat(new Materials(mat)), words(new Words(words)) {}
/**
* Constructeur de la classe Element prenant en entrée un materials.
*
* @param mat La matière associée à l'élément.
*/
Element::Element(Materials mat) : mat(new Materials(mat)),words(nullptr) {}
/**
* Constructeur de la classe Element prenant en entrée un words.
*
* @param mat La matière associée à l'élément.
*/
Element::Element(Words words) : words(new Words(words)),mat(nullptr) {}
/**
 * Opérateur d'égalité pour la classe Element.
 *
 * @param rhs L'autre instance d'Element à comparer.
 * @return true si les instances sont égales, sinon false.
 */
bool Element::operator==(const Element &rhs) const {
    if(words == nullptr && mat != nullptr){
        return mat->getIcon() == rhs.mat->getIcon();
    }else if(words != nullptr && &words->getSubject() != nullptr && &words->getComplement()== nullptr &&  &words->getOperator() == nullptr && mat == nullptr){
        return words->getSubject().getSubjectEnum() == rhs.words->getSubject().getSubjectEnum();
    }else if(words != nullptr && &words->getSubject() == nullptr && &words->getComplement()!= nullptr &&  &words->getOperator() == nullptr && mat == nullptr){
        return words->getComplement().getComplementEnum() == rhs.words->getComplement().getComplementEnum();
    }else if(words != nullptr && &words->getSubject() == nullptr && &words->getComplement()== nullptr &&  &words->getOperator() != nullptr && mat == nullptr){
        return words->getOperator().getOperatorEnum() == rhs.words->getOperator().getOperatorEnum();
    }
}
/**
 * Opérateur de différence pour la classe Element.
 *
 * @param rhs L'autre instance d'Element à comparer.
 * @return true si les instances sont différentes, sinon false.
 */
bool Element::operator!=(const Element &rhs) const {
    return !(rhs == *this);
}
/**
 *  Accesseur pour le materials associée à l'élément.
 *
 * @return Un pointeur vers le materiels associée à l'élément.
 */
Materials *Element::getMat() const {
    return this->mat;
}
/**
 * Accesseur pour les mots associés à l'élément.
 *
 * @return Un pointeur vers les words associés à l'élément.
 */
Words *Element::getWords() const {
    return this->words;
}


