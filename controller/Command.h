//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_COMMAND_H
#define UNTITLED1_COMMAND_H

#include "../model/DnaData.h"
class Command
{
public:
    virtual std::string get_message() = 0;
    virtual void action(DnaData & danData, char ** args) = 0;
//    virtual void help() = 0;

protected:
    std::string m_message;

};

#endif //UNTITLED1_COMMAND_H
