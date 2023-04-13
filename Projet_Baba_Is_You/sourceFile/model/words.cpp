//
// Created by elhar on 25-03-23.
//



#include "../../headerFile/model/words.h"
#include "../../headerFile/model/subject.h"
#include "../../headerFile/model/operator.h"
#include "../../headerFile/model/complement.h"


Words::Words(Subject subject) : subject_(subject){}

Words::Words(Operator op) : operator_(op) {}

Words::Words(Complement complement) : complement_(complement) {}

Words::Words() {}



