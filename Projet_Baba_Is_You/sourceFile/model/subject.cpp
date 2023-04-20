//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/subject.h"

/**

Constructeur de la classe Subject.
@param subjectEnum L'énumération représentant le type de sujet(BABA,ROCK,...) associé à l'objet Subject.
*/
Subject::Subject(SubjectEnum subjectEnum) : subjectEnum(subjectEnum) {
    stop = false;
    win = false;
    push = false;
    kill = false;
    sink = false;
    best = false;
    you = false;
}

/**

Getter pour récupérer l'énumération représentant le type de sujet associé à l'objet Subject.
@return L'énumération représentant le type de sujet associé à l'objet Subject.
*/
SubjectEnum Subject::getSubjectEnum() const {
    return subjectEnum;
}

/**

Setter pour définir l'énumération représentant le type de sujet associé à l'objet Subject.
@param newSubjectEnum La nouvelle énumération représentant le type de sujet à associer à l'objet Subject.
*/
void Subject::setSubjectEnum(SubjectEnum newSubjectEnum) {
    Subject::subjectEnum = newSubjectEnum;
}

/**

Setter pour définir si le sujet possède l'effet "STOP".
@param stop Booléen indiquant si le sujet possède l'effet "STOP".

*/
void Subject::setStop(bool stop) {
    Subject::stop = stop;
}

/**

Setter pour définir si le sujet possède l'effet "WIN".
@param win Booléen indiquant si le sujet possède l'effet "WIN".
*/

void Subject::setWin(bool win) {
    Subject::win = win;
}

/**

Setter pour définir si le sujet possède l'effet "PUSH".
@param push Booléen indiquant si le sujet possède l'effet "PUSH".
*/
void Subject::setPush(bool push) {
    Subject::push = push;
}

/**

Setter pour définir si le sujet possède l'effet "KILL".
@param kill Booléen indiquant si le sujet possède l'effet "KILL".
*/
void Subject::setKill(bool kill) {
    Subject::kill = kill;
}

/**

Setter pour définir si le sujet possède l'effet "SINK".
@param sink Booléen indiquant si le sujet possède l'effet "SINK".
*/
void Subject::setSink(bool sink) {
    Subject::sink = sink;
}

/**

Setter pour définir si le sujet possède l'effet "BEST".
@param sink Booléen indiquant si le sujet possède l'effet "BEST".

*/
void Subject::setBest(bool best) {
    Subject::best = best;
}

/**

Setter pour définir si le sujet possède l'effet "YOU".
@param sink Booléen indiquant si le sujet possède l'effet "YOU".
*/
void Subject::setYou(bool you) {
    Subject::you = you;
}

/**
Getter pour récupérer l'effet "STOP" associé à l'objet Subject.
*/
bool Subject::isStop() const {
    return stop;
}

/**
Getter pour récupérer l'effet "WIN" associé à l'objet Subject.
*/
bool Subject::isWin() const {
    return win;
}

/**
Getter pour récupérer l'effet "PUSH" associé à l'objet Subject.
*/
bool Subject::isPush() const {
    return push;
}

/**
Getter pour récupérer l'effet "KILL" associé à l'objet Subject.
*/
bool Subject::isKill() const {
    return kill;
}

/**
Getter pour récupérer l'effet "SINK" associé à l'objet Subject.
*/
bool Subject::isSink() const {
    return sink;
}

/**
Getter pour récupérer l'effet "BEST" associé à l'objet Subject.
*/
bool Subject::isBest() const {
    return best;
}

/**
Getter pour récupérer l'effet "YOU" associé à l'objet Subject.
*/
bool Subject::isYou() const {
    return you;
}
/**

Opérateur de comparaison d'égalité entre deux objets Subject.
@param rhs L'objet Subject à comparer avec l'objet courant.
@return Booléen indiquant si les deux objets sont égaux en comparant leur énumération de sujet et les effets associés.
*/
bool Subject::operator==(const Subject &rhs) const {
    return subjectEnum == rhs.subjectEnum &&
           stop == rhs.stop &&
           win == rhs.win &&
           push == rhs.push &&
           kill == rhs.kill &&
           sink == rhs.sink &&
           best == rhs.best &&
           you == rhs.you;
}
/**

Opérateur de comparaison de non-égalité entre deux objets Subject.
@param rhs L'objet Subject à comparer avec l'objet courant.
@return Booléen indiquant si les deux objets sont différents en comparant leur énumération de sujet et les effets associés.
*/
bool Subject::operator!=(const Subject &rhs) const {
    return !(rhs == *this);
}


