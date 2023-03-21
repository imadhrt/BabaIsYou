//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_SUBJECT_H
#define PROJET_BABA_IS_YOU_SUBJECT_H

#include "enum.h"
#include "words.h"

class Subject:public Words{
public:
    explicit Subject(SubjectEnum subjectEnum);

    SubjectEnum getSubjectEnum() const;

    void setSubjectEnum(SubjectEnum subjectEnum);

private:
    SubjectEnum subjectEnum;

};

Subject::Subject(SubjectEnum subjectEnum) : subjectEnum(subjectEnum) {}

SubjectEnum Subject::getSubjectEnum() const {
    return subjectEnum;
}

void Subject::setSubjectEnum(SubjectEnum subjectEnum) {
    Subject::subjectEnum = subjectEnum;
}

#endif //PROJET_BABA_IS_YOU_SUBJECT_H
