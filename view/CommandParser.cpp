#include <clocale>
#include <cstring>
#include "CommandParser.h"
#include <string>
#include <iostream>

//
// Created by cglick on 12/27/18.
//
void CommandParser::parse(char * const & input, char ** const & argv)
{
    const char delim[]={'\t','\n',' '};

    int i;
    i= 0;

    argv[i] = strtok(input, " ");

    while(argv[i] != NULL)
    {
        argv[++i]= strtok(NULL, delim);
    }

    argv[i] = NULL;


}
