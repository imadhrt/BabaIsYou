//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/subject.h"

Subject::Subject(SubjectEnum newSubjectEnum) : subjectEnum(newSubjectEnum) {}

SubjectEnum Subject::getSubjectEnum() const {
    return subjectEnum;
}


void Subject::setSubjectEnum(SubjectEnum newSubjectEnum) {
    Subject::subjectEnum = newSubjectEnum;
}