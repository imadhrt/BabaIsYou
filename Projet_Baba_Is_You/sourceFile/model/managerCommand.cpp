//
// Created by elhar on 25-03-23.
//

#include "../../headerFile/model/command.h"
#include "../../headerFile/model/managerCommand.h"


/**
 * Allows to add the command in the stack
 *
 * @param command is a command
 */
    void ManagerCommand::addCommand(Command* command) {
        command->execute();
        undoStack.push(command);
        redoStack = std::stack<Command*>();
    }

    /**
     * Allows to return to the movement make
     */
    void ManagerCommand::undo() {
        if (!undoStack.empty()) {
            Command* command = undoStack.top();
            undoStack.pop();
            if(command->unexecute()) {
                redoStack.push(command);
            }
        }
    }

    /**
     * Allows to return to the movement make cancel
     */
    void ManagerCommand::redo() {
        if (!redoStack.empty()) {
            Command* command = redoStack.top();
            redoStack.pop();
            if(command->execute()) {
                undoStack.push(command);
            }
        }
    }

