//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_NEW_H
#define UNTITLED1_NEW_H

#include "../controller/Command.h"
class New:public Command
{
public:
    New();
    std::string get_message();
    void action(DnaData & dnaData, char ** args);


};

#endif //UNTITLED1_NEW_H
