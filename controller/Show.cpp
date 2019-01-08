//
// Created by cglick on 1/6/19.
//

#include <sstream>
#include "Show.h"

void Show::action(DnaData &dnaData, char **args)
{
    dnaData.addSeuance(args[0],args[1]);
    std::ostringstream s;
    s << "[" << dnaData.getLastId() << "] " << dnaData.getLastname() << ":" << args[0] << std::endl;
    m_message = s.str();

}

std::string Show::get_message()
{
    return m_message;
}