//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/subject.h"

Subject::Subject(SubjectEnum subjectEnum) : subjectEnum(subjectEnum) {
    stop = false;
    win = false;
    push = false;
    kill = false;
    sink = false;
    best = false;
    you = false;
}

SubjectEnum Subject::getSubjectEnum() const {
    return subjectEnum;
}


void Subject::setSubjectEnum(SubjectEnum newSubjectEnum) {
    Subject::subjectEnum = newSubjectEnum;
}


void Subject::setStop(bool stop) {
    Subject::stop = stop;
}

void Subject::setWin(bool win) {
    Subject::win = win;
}

void Subject::setPush(bool push) {
    Subject::push = push;
}

void Subject::setKill(bool kill) {
    Subject::kill = kill;
}

void Subject::setSink(bool sink) {
    Subject::sink = sink;
}

void Subject::setBest(bool best) {
    Subject::best = best;
}

void Subject::setYou(bool you) {
    Subject::you = you;
}

bool Subject::isStop() const {
    return stop;
}

bool Subject::isWin() const {
    return win;
}

bool Subject::isPush() const {
    return push;
}

bool Subject::isKill() const {
    return kill;
}

bool Subject::isSink() const {
    return sink;
}

bool Subject::isBest() const {
    return best;
}

bool Subject::isYou() const {
    return you;
}

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

bool Subject::operator!=(const Subject &rhs) const {
    return !(rhs == *this);
}


