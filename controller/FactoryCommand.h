//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_FACTORYCOMMAND_H
#define UNTITLED1_FACTORYCOMMAND_H

#include <map>
#include "Command.h"

typedef Command* (*pCreat)();


class FactoryCommand
{
public:
    FactoryCommand();
    ~FactoryCommand();
    void addCommand(char *, pCreat);
    Command* getCommand(const char * command);
private:
    std::map<std::string,Command*> m_commands;
};


#endif //UNTITLED1_FACTORYCOMMAND_H
