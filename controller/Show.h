//
// Created by cglick on 1/6/19.
//

#ifndef DNA_SHOW_H
#define DNA_SHOW_H

#include "Command.h"

class Show:public Command
{
public:
    std::string get_message();
    void action(DnaData & dnaData, char ** args);
};

#endif //DNA_SHOW_H
