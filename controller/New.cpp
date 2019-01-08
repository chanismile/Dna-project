//
// Created by cglick on 12/27/18.
//

#include <sstream>
#include <iostream>
#include "New.h"
New::New() {}

void New::action(DnaData & dnaData, char **args)
{
    dnaData.addSeuance(args[0],args[1]);
    std::ostringstream s;
    s << "[" << dnaData.getLastId() << "] " << dnaData.getLastname() << ":" << args[0] << std::endl;
    m_message = s.str();
}

std::string New::get_message()
{
    return m_message;
    //return "al";
}