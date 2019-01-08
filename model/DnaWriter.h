//
// Created by cglick on 10/31/18.
//

#ifndef UNTITLED1_DNAWRITER_H
#define UNTITLED1_DNAWRITER_H

#include "DnaSequence.h"
#include <fstream>
class DnaWriter
{
public:
    DnaWriter(const char * file_name);
    ~DnaWriter();
    void write(DnaSequence & dna);
    void write(IDna * dna);

private:
    std::ofstream m_write;
};
#endif //UNTITLED1_DNAWRITER_H
