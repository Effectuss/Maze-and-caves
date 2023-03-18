#include "controller.h"

Controller* Controller::controller_= nullptr;

void Controller::Restart() {
    if(controller_){
        delete controller_;
    }
}

Controller* Controller::GetController() {
    if(!controller_) {
        controller_ = new Controller();
    }
    return controller_;
}