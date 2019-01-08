//
// Created by cglick on 10/29/18.
//

#ifndef UNTITLED1_DNAREADERTEXT_H
#define UNTITLED1_DNAREADERTEXT_H

#include <fstream>
#include "DnaSequence.h"

//class DnaSequence;
class DnaReaderText{

public:
    DnaReaderText(const char * fileName);
    ~DnaReaderText();
    DnaSequence read();

private:
    std::ifstream m_read;

};
#endif //UNTITLED1_DNAREADERTEXT_H
