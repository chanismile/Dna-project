//
// Created by cglick on 12/27/18.
//

#include <string>
#include <cstring>
#include "Cmd.h"
#include <iostream>
#include <stdlib.h>
#include <cstdio>

Cmd::Cmd()
{
//    m_controller = new Controller();
}
Cmd::~Cmd()
{
//    m_controller = new Controller();
}

void Cmd::exit()
{
    std::exit(0);

}

void typePrompt()
{
    printf("cmd >>");
}

void Cmd::run()
{
    char input[70];
    char * afterParse[70];

    while (true)
    {
        typePrompt();
        fgets(input,70 , stdin);

        if (strcmp(input, "exit")==0 )
        {
            exit();
        }

        CommandParser::parse(input, afterParse);
        std::cout << m_controller.rumCommand(afterParse[0],afterParse + 1);
    }
}