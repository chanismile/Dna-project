//
// Created by cglick on 1/6/19.
//

#include <sstream>
#include "Save.h"
#include "../model/DnaWriter.h"


std::string Save::get_message()
{
    return m_message;
}

void Save::action(DnaData &dnaData, char **args)
{
    DnaWriter * dnaWriter;
    if (!args[1])
    {
        std::cout << "ooooooppppppppsssss";
    }
    else
    {
        dnaWriter =new DnaWriter(args[1]);
    }

    std::istringstream istringstream(args[0]);
    int indx;

    istringstream >> indx;
    dnaWriter->write(dnaData.getSeqById(indx));

    std::ostringstream s;
    s << "[" << args[0] << "] " << dnaData.getNameById(indx) << " saved to " << args[1] << std::endl;
    m_message = s.str();
}