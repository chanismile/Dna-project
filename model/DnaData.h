//
// Created by cglick on 12/25/18.
//

#ifndef UNTITLED1_DNADATA_H
#define UNTITLED1_DNADATA_H

#include "DnaMetaData.h"
#include <map>
#include <utility>

class DnaData
{
public:
    void addSeuance(const std::string & seq,const char * name);
    void addSeuance(DnaSequence seq,const char * name);
    size_t getLastId();
    std::string getLastname();
    IDna * getSeqById(size_t id);
    std::string getNameById(size_t id);
    std::string getStringSeqById(size_t id);


private:
    std::map<int,DnaMetaData *> m_dnaByInt;
    std::map<std::string,DnaMetaData *> m_dnaByString;

    static size_t idCounter;
    static size_t namesCounter;
    static std::string lastNameInserted;

};


#endif //UNTITLED1_DNADATA_H
