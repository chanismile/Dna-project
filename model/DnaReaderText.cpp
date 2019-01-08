//
// Created by cglick on 10/29/18.
//

#include "DnaReaderText.h"
DnaReaderText::DnaReaderText(const char * fileName)
{
    m_read.open(fileName);
    if(!m_read.is_open())
    {
        throw std::runtime_error("Error in opening input file.\n");
    }

}
DnaReaderText::~DnaReaderText()
{
    m_read.close();

}
DnaSequence DnaReaderText::read() {

    m_read.seekg (0, std::ios::end);
    int length = m_read.tellg();
    m_read.seekg(0);
    char * output = new char[length+1];
    while (!m_read.eof()) {
        m_read >> output;
    }
    DnaSequence dnaSequence(output);
    delete[] output;
    return dnaSequence;
}
//DnaSequence DnaReaderText::read() {
//
//    m_read.seekg (0, std::ios::end);
//    int length = m_read.tellg();
//    m_read.seekg(0);
//    char * output = new char[length+1];
//    while (!m_read.eof()) {
//        m_read >> output;
//    }
//    DnaSequence dnaSequence(output);
//    delete[] output;
//    return dnaSequence;
//}

