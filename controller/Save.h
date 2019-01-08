//
// Created by cglick on 1/6/19.
//

#ifndef DNA_SAVE_H
#define DNA_SAVE_H

#include "Command.h"

class Save:public Command
{
public:
    std::string get_message();
    void action(DnaData & dnaData, char ** args);
};

#endif //DNA_SAVE_H
