//
// Created by cglick on 12/25/18.
//

#include "DnaData.h"
#include <sstream>
size_t DnaData::idCounter = 0;
size_t DnaData::namesCounter = 0;
std::string DnaData::lastNameInserted = "";
size_t MAX_LENGTH = 30;

void DnaData::addSeuance(const std::string & seq,const char * name)
{
    ++idCounter;
    DnaMetaData* dnaMetaData;

    if (!name)
    {
        std::ostringstream s;
        s << "seq" << ++namesCounter;
        lastNameInserted = s.str();
        dnaMetaData = new DnaMetaData(seq, idCounter, lastNameInserted);
        m_dnaByString.insert(std::make_pair(lastNameInserted, dnaMetaData));

    }
    else
    {
        lastNameInserted = name;
        dnaMetaData = new DnaMetaData(seq, idCounter, name + 1);
        m_dnaByString.insert(std::make_pair(name + 1, dnaMetaData));

    }

    m_dnaByInt.insert(std::make_pair(idCounter, dnaMetaData));

}

void DnaData::addSeuance(DnaSequence seq,const char * name)
{
    ++idCounter;
    DnaMetaData* dnaMetaData;

    if (!name)
    {
        std::ostringstream s;
        s << "seq" << ++namesCounter;
        lastNameInserted = s.str();
        dnaMetaData = new DnaMetaData(seq, idCounter, lastNameInserted);
        m_dnaByString.insert(std::make_pair(lastNameInserted, dnaMetaData));

    }
    else
    {
        lastNameInserted = name;
        dnaMetaData = new DnaMetaData(seq, idCounter, name + 1);
        m_dnaByString.insert(std::make_pair(name + 1, dnaMetaData));

    }

    m_dnaByInt.insert(std::make_pair(idCounter, dnaMetaData));

}


size_t DnaData::getLastId()
{
    return idCounter;
}

std::string DnaData::getLastname()
{
    return lastNameInserted;
}

IDna * DnaData::getSeqById(size_t id)
{
    return m_dnaByInt[id]->getm_IDna();
}


std::string DnaData::getStringSeqById(size_t id)
{
    std::ostringstream s;
    IDna * iDna = m_dnaByInt[id]->getm_IDna();
    int len = std::min(iDna->sequence_length(),MAX_LENGTH);

    for (int i = 0; i < len ; ++i)
    {
        s << (*iDna)[i];
    }
    return s.str();
}

std::string DnaData::getNameById(size_t id)
{
    return m_dnaByInt[id]->getm_name();
}
