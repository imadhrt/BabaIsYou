//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_SUBJECT_H
#define PROJET_BABA_IS_YOU_SUBJECT_H

#include "enum.h"


class Subject{
private:
    SubjectEnum subjectEnum;
    bool stop;
    bool win;
    bool push;
    bool kill;
    bool sink;
    bool best;
    bool you;

public:
    Subject(SubjectEnum newSubjectEnum);
    Subject()=default;

    bool isStop() const;

    bool isWin() const;

    bool operator==(const Subject &rhs) const;

    bool operator!=(const Subject &rhs) const;

    bool isPush() const;

    bool isKill() const;

    bool isSink() const;

    bool isBest() const;

    bool isYou() const;

    SubjectEnum getSubjectEnum() const;

    void setSubjectEnum(SubjectEnum newSubjectEnum);

    void setStop(bool stop);

    void setWin(bool win);

    void setPush(bool push);

    void setKill(bool kill);

    void setSink(bool sink);

    void setBest(bool best);

    void setYou(bool you);

};


#endif //PROJET_BABA_IS_YOU_SUBJECT_H
