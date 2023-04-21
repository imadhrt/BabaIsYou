//
// Created by Mamoun benmassaoud on 21/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_MOVECOMMAND_H
#define PROJET_BABA_IS_YOU_MOVECOMMAND_H
#include <vector>

#include "../../headerFile/model/babaisyou.h"
#include "../../headerFile/model/command.h"

class MoveCommand : public Command {
public:
    MoveCommand(BabaIsYou* babaIsYou, dev4::Direction direction);

    bool execute() override;
    bool unexecute() override;

private:
    BabaIsYou* babaIsYou_;
    BabaIsYou* babaIsYouBeforeExecution;
    dev4::Direction direction_;
};

#endif //PROJET_BABA_IS_YOU_MOVECOMMAND_H
