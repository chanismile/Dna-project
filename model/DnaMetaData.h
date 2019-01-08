//
// Created by cglick on 12/29/18.
//

#ifndef UNTITLED1_DNAMETADATA_H
#define UNTITLED1_DNAMETADATA_H

#include "DnaSequence.h"
#include <glob.h>
#include <string>

enum Status{ Up_TO_DATE, MODIFIED, NEW };

class DnaMetaData
{
public:
    DnaMetaData(const std::string & seq, size_t id, const std::string & name);
    DnaMetaData(DnaSequence seq, size_t id, const std::string & name);
    IDna * getm_IDna();
    std::string getm_name();

private:
    size_t m_id;
    std::string m_name;
    IDna * m_IDna;
    Status m_status;

};

#endif //UNTITLED1_DNAMETADATA_H
