//
// Created by cglick on 12/27/18.
//

#include <iostream>
#include "Controller.h"

std::string Controller::rumCommand(char *command, char ** args)
{
    Command* cmnd  = (m_factoryCommand.getCommand(command));
    cmnd->action(m_dnaData, args);
    return cmnd->get_message();


}

