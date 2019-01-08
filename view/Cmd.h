//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_COMMANDLINE_H
#define UNTITLED1_COMMANDLINE_H

#include "UI.h"
#include "CommandParser.h"
#include "../controller/Controller.h"

class Cmd:public UI
{
public:
    Cmd();
    ~Cmd();
    void run();
    void exit();

private:
    Controller m_controller;
};

#endif //UNTITLED1_COMMANDLINE_H
