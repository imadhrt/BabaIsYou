//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/words.h"


/**
 * Constructeur pour créer un objet Words contenant un sujet.
 * @param subject le sujet associé à l'objet Words.
 */
Words::Words(Subject subject) : subject_(new Subject(subject)), operator_(nullptr), complement_(nullptr){}
/**
 * Constructeur pour créer un objet Words contenant un operateur.
 * @param op l'operateur associé à l'objet Words.
 */
Words::Words(Operator op) : operator_(new Operator(op)), subject_(nullptr), complement_(nullptr) {}
/**
 * Constructeur pour créer un objet Words contenant un complement.
 * @param complement le complement associé à l'objet Words.
 */
Words::Words(Complement complement) : complement_(new Complement(complement)), subject_(nullptr), operator_(nullptr) {}

/**
* Méthode pour récupérer le sujet associé à l'objet Words.
* @return Le sujet associé à l'objet Words.
*/
const Subject &Words::getSubject() const {
    return *this->subject_;
}
/**
* Méthode pour récupérer l'opérateur associé à l'objet Words.
* @return L'opérateur associé à l'objet Words.
*/
const Operator &Words::getOperator() const {
    return *this->operator_;
}
/**
* Méthode pour récupérer le complement associé à l'objet Words.
* @return Le complement associé à l'objet Words.
*/
const Complement &Words::getComplement() const {
    return *this->complement_;
}






