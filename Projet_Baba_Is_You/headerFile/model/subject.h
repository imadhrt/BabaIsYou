//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_SUBJECT_H
#define PROJET_BABA_IS_YOU_SUBJECT_H

#include "enum.h"


class Subject{
private:
    SubjectEnum subjectEnum;
public:
    explicit Subject(SubjectEnum newSubjectEnum);
    Subject()=default;
    SubjectEnum getSubjectEnum() const;

    void setSubjectEnum(SubjectEnum newSubjectEnum);



};


#endif //PROJET_BABA_IS_YOU_SUBJECT_H
