

#include <iostream>
#include "../../headerFile/model/moveCommand.h"

MoveCommand::MoveCommand(BabaIsYou* babaIsYou, dev4::Direction direction) : babaIsYou_(babaIsYou), direction_(direction) {}

bool MoveCommand::execute() {
    babaIsYouBeforeExecution = new BabaIsYou(*babaIsYou_);
    try {
        babaIsYou_->move(direction_);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return true;
}

bool MoveCommand::unexecute()  {
    bool levelChanged = babaIsYouBeforeExecution->getBoard()->getFile().getLevel() == babaIsYou_->getBoard()->getFile().getLevel();
    bool sameBabaIsYou = babaIsYouBeforeExecution->getBoard() != babaIsYou_->getBoard();


    bool canUnexecute = levelChanged && sameBabaIsYou;
    if(canUnexecute){
        babaIsYou_->revertTo(babaIsYouBeforeExecution);
    }
    return canUnexecute;
}

