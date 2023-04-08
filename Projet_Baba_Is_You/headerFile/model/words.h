//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_WORDS_H
#define PROJET_BABA_IS_YOU_WORDS_H

#include "element.h"

class Words: public Element{
private:

    Words* words;
public:
     Words(Words *newWords);

     Words();

    Words getWords() const;

    void setWords(Words *newWords);






};



#endif //PROJET_BABA_IS_YOU_WORDS_H
