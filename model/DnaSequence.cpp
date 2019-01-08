//
// Created by cglick on 10/24/18.
//

#include "DnaSequence.h"
#include <fstream>
using std::ostream;
using std::endl;
/*************global functions******************/
inline bool chack_sequence_len_validation(const char * seq)
{
    if (strlen(seq)%3 != 0)
    {
        throw "ERROR IN CREATING DNA: INVALID SEQUENCE LENGTH";
    }
    return true;
}

/*************DnaSequence functions decleration***************/

DnaSequence::DnaSequence(const char * sequence)
{
    chack_sequence_len_validation(sequence);
    set_sequence_and_size(sequence);
}

DnaSequence::DnaSequence(std::string sequence)
{
    chack_sequence_len_validation(sequence.c_str());
    set_sequence_and_size(sequence.c_str());
}

DnaSequence::DnaSequence(const DnaSequence & other)
{
    set_sequence_and_size(other.sequence,other.size);
}

DnaSequence::DnaSequence(const DnaSequence & other,size_t from, size_t to)
{
    if(from > to || to > other.size)
    {
        throw std::out_of_range("range is incorrect");
    }
    size= to - from;
    sequence = new Nucleotide[size];
    for(size_t i=from,j=0; i < to; i++,j++)
    {
        sequence[j] = other.sequence[i];
    }

}
DnaSequence::DnaSequence(Nucleotide & other,size_t s)
{
    size = s;
    sequence = &other;
}

DnaSequence::~DnaSequence()
{
    delete[] sequence;
}
void DnaSequence::set_sequence_and_size(const char *seq)
{
    try {
        size = strlen(seq);
        this->sequence = new Nucleotide[size];
        for (size_t i = 0; i < size; i++)
        {
            this->sequence[i] = seq[i];
        }
    }
    catch (char const * s)
    {
        delete[] sequence;
        throw s;
    }
}
void DnaSequence::set_sequence_and_size(const Nucleotide *seq,int s)
{
    size=s;
    sequence = new Nucleotide[size];
    for (size_t i = 0; i < size; i++)
    {
        sequence[i] = seq[i];
    }

}

Nucleotide & DnaSequence::operator[](size_t i)
{
    if(i > size){
        throw std::out_of_range("range is incorrect");
    }
    return sequence[i];
}
Nucleotide & DnaSequence::operator[](size_t i)const
{
    if(i > size){
        throw std::out_of_range("range is incorrect");
    }
    return sequence[i];
}
DnaSequence& DnaSequence::operator=(const DnaSequence & other)
{
    Nucleotide * nucleotide=new Nucleotide[other.size];
    size = other.size;
    for (size_t i = 0; i < size; ++i)
    {
        nucleotide[i] = other.sequence[i];
    }
	delete[] sequence;
    sequence = nucleotide;
    return *this;
}
DnaSequence& DnaSequence::operator=(const char * seq)
{
    chack_sequence_len_validation(seq);
    delete[] sequence;
    set_sequence_and_size(seq);
    return *this;
}
DnaSequence& DnaSequence::operator=(std::string sequence)
{
    const char * charPtrSequence=sequence.c_str();
    return operator=(charPtrSequence);
}

bool DnaSequence::operator!=(DnaSequence &dnaSequence)
{
	return !(*this == dnaSequence);
}
size_t DnaSequence::sequence_length() const
{
    return size;
}
DnaSequence DnaSequence::get_slice(size_t from, size_t to)
{
   DnaSequence a(*this,from,to);
    return a;
}
/*void DnaSequence::writeToFile(char *name) {
    std::ofstream myFile;
    myFile.open(name);
    myFile<<*this;
    myFile.close();
}*/
DnaSequence DnaSequence::paring(){
    Nucleotide* newNucleotide = new Nucleotide[size];
    for (size_t i = 0; i < size; ++i) {
        newNucleotide[i] = sequence[size-1 - i].flip();
    }
    DnaSequence a(*newNucleotide,size);
    return a;
}


ostream & operator<<(ostream& os, DnaSequence& dnaSequence){
    for (size_t i=0; i< dnaSequence.size; i++) {
        os << dnaSequence.sequence[i];
    }
    os<<endl;
    return os;

}
