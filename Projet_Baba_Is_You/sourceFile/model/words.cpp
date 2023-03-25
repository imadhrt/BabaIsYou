//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/words.h"

Words::Words(Words *newWords) : words(newWords) {}

Words Words::getWords() const {
    return *this->words;
}

void Words::setWords(Words *newWords) {

    Words::words = newWords;
}
Words::Words():words(nullptr) {}