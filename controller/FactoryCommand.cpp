//
// Created by cglick on 12/27/18.
//
#include "FactoryCommand.h"
#include "New.h"
#include "Load.h"
#include "Save.h"

FactoryCommand::FactoryCommand()
{
    m_commands.insert(std::make_pair<std::string ,Command*>("new",new New()));
    m_commands.insert(std::make_pair<std::string ,Command*>("load",new Load()));
    m_commands.insert(std::make_pair<std::string ,Command*>("save",new Save()));
}
FactoryCommand::~FactoryCommand() {}

//void FactoryCommand::addCommand(char * command, pCreat creationFunc)
//{
//    m_commands[command] = creationFunc;
//}

Command* FactoryCommand::getCommand(const char *command)
{
    return m_commands[command];
}