//
// Created by Mamoun benmassaoud on 21/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_COMMAND_H
#define PROJET_BABA_IS_YOU_COMMAND_H

class Command {
public:
    virtual bool execute() = 0;
    virtual bool unexecute() = 0;
};

#endif //PROJET_BABA_IS_YOU_COMMAND_H
