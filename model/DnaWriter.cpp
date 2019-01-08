//
// Created by cglick on 10/31/18.
//

#include "DnaWriter.h"
DnaWriter::DnaWriter(const char *file_name) {
    m_write.open(file_name);
    if(!m_write.is_open())
    {
        throw std::runtime_error("Error in opening output file.\n");
    }

}
DnaWriter::~DnaWriter() {
    m_write.close();
}
void DnaWriter::write(DnaSequence &dna) {
    m_write<<dna;
}

void DnaWriter::write(IDna * dna) {
    for (unsigned int i = 0; i < dna->sequence_length(); ++i)
    {
        std::cout << (*dna)[i] << std::endl;
        m_write<<(*dna)[i];
    }

}