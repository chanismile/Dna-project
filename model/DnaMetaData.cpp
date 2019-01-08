//
// Created by cglick on 12/29/18.
//

#include "DnaMetaData.h"
DnaMetaData::DnaMetaData(const std::string & seq, size_t id, const std::string & name):m_id(id), m_name(name),m_IDna(new DnaSequence(seq)),m_status(NEW)
{}

DnaMetaData::DnaMetaData(DnaSequence iDna, size_t id, const std::string &name) :m_id(id), m_name(name), m_IDna(&iDna), m_status(NEW)
{}

IDna* DnaMetaData::getm_IDna()
{
    return m_IDna;
}

std::string DnaMetaData::getm_name()
{
    return m_name;
}
//std::ostream& operator<<(std::ostream& os, DnaMetaData& dnaMetaData)
//{
//    IDna * iDna = m_dnaByInt[id]->getm_IDna();
//    int len = std::min(iDna->sequence_length(),MAX_LENGTH);
//    for (int i = 0; i < len ; ++i)
//    {
//        os << (*iDna)[i];
//    }
//    return os;
//}