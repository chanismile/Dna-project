//
// Created by cglick on 1/3/19.
//

#ifndef DNA_LOAD_H
#define DNA_LOAD_H

#include "Command.h"

class Load:public Command
{
public:
    std::string get_message();
    void action(DnaData & dnaData, char ** args);
};

#endif //DNA_LOAD_H
