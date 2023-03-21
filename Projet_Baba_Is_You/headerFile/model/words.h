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
    explicit Words(Words *words);

     Words();

    Words *getWords() const;

    void setWords(Words *words);






};

Words::Words(Words *words) : words(words) {}

Words *Words::getWords() const {
    return words;
}

void Words::setWords(Words *words) {

    Words::words = words;
}
Words::Words():words(nullptr) {}

#endif //PROJET_BABA_IS_YOU_WORDS_H
