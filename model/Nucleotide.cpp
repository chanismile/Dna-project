//
// Created by cglick on 1/6/19.
//

#include "Nucleotide.h"

std::ostream & operator<<(std::ostream& os, Nucleotide& nucleotide)
{
    os << nucleotide.c;
    return os;
}