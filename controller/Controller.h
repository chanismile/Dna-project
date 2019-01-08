//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_CONTROLLER_H
#define UNTITLED1_CONTROLLER_H

#include "../model/DnaData.h"
#include "Command.h"
#include "FactoryCommand.h"
#include "../view/UI.h"

class Controller
{
public:
    std::string rumCommand(char * command, char ** args);
private:
    FactoryCommand m_factoryCommand;
    DnaData m_dnaData;

};


#endif //UNTITLED1_CONTROLLER_H
