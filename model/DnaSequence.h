//
// Created by cglick on 10/24/18.
//
#include <string>
#include <cstring>
#ifndef UNTITLED1_DNASEQUENCE_H
#define UNTITLED1_DNASEQUENCE_H

#include "Nucleotide.h"
#include "Idna.h"

class DnaSequence:public IDna
{
public:
    explicit DnaSequence(const char * sequence);
    explicit DnaSequence(std::string  sequence);
    DnaSequence(const DnaSequence & dnaSequence);
    ~DnaSequence();

    DnaSequence& operator=(const DnaSequence & other);
    DnaSequence& operator=(const char * sequence);
    DnaSequence& operator=(const std::string sequence);
    bool operator==(DnaSequence& dnaSequence);
    bool operator!=(DnaSequence& dnaSequence);

    size_t sequence_length() const;
    DnaSequence get_slice(size_t from, size_t to);
    DnaSequence paring();

    Nucleotide & operator[](size_t i);
    Nucleotide & operator[](size_t i) const;

    /*void writeToFile(char * name);
    char * readFromFile(char * name);*/

    friend std::ostream& operator<<(std::ostream& os, DnaSequence& dnaSequence);

private:
    explicit DnaSequence(const DnaSequence & other,size_t from, size_t to);
    explicit DnaSequence(Nucleotide & other,size_t s);
    void set_sequence_and_size(const char * seq);
    void set_sequence_and_size(const Nucleotide * seq, int size);

private:
    Nucleotide * sequence;
    size_t size;

};

inline bool DnaSequence::operator==(DnaSequence &dnaSequence) {
    if(size != dnaSequence.size){
        return false;
    }
    for(size_t i = 0; i < size; i++){
        if(sequence[i] != dnaSequence.sequence[i]){
            return false;
        }
    }
    return true;
}
#endif //UNTITLED1_DNASEQUENCE_H
