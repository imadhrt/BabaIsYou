//
// Created by elhar on 25-03-23.
//

#ifndef PROJET_BABA_IS_YOU_MANAGERCOMMAND_H
#define PROJET_BABA_IS_YOU_MANAGERCOMMAND_H

#include <stack>
#include "command.h"

class ManagerCommand {
private:
    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;

public:
    /**
     * Allows to add the command in the stack
     *
     * @param command is a command
     */
    void addCommand(Command* command);

    /**
     * Allows to return to the movement make
     */
    void undo();

    /**
     * Allows to return to the movement make cancel
     */
    void redo();
};

#endif //PROJET_BABA_IS_YOU_MANAGERCOMMAND_H
