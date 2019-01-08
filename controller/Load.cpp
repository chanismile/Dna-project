//
// Created by cglick on 1/3/19.
//

#include "Load.h"
#include <sstream>
#include "../model/DnaReaderText.h"

void Load::action(DnaData &dnaData, char **args)
{
    DnaReaderText dnaReaderText(args[0]);
    dnaData.addSeuance(dnaReaderText.read(), args[1]);
    std::ostringstream s;
    s << "[" << dnaData.getLastId() << "] " << dnaData.getLastname() << ":" << dnaData.getStringSeqById(dnaData.getLastId()) << std::endl;
    m_message = s.str();
}

std::string Load::get_message()
{
    return m_message;
}