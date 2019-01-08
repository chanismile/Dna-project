//
// Created by cglick on 1/6/19.
//

#ifndef DNA_NUCLEOTIDE_H
#define DNA_NUCLEOTIDE_H

#include <iostream>

class Nucleotide{
public:
    Nucleotide();
    Nucleotide(char c);
    Nucleotide& operator=(const char c);
    operator char();
    char flip();
    friend std::ostream & operator<<(std::ostream& os, Nucleotide& nucleotide);

private:
    void checkChar(const char ch);

private:
    char c;

};


inline Nucleotide::Nucleotide():c('A'){}

inline Nucleotide::Nucleotide(char ch)
{
    ch = toupper(ch);

    if(ch != 'A' && ch != 'G' && ch != 'C' && ch != 'T')
    {
        throw "invalied input\n";
    }
    c=ch;
}

inline Nucleotide & Nucleotide::operator=(const char ch)
{
    c=Nucleotide(ch);
    return *this;
}

inline Nucleotide::operator char()
{
    return c;
}

inline void Nucleotide::checkChar(const char ch)
{
    if(ch != 'A' && ch != 'G' && ch != 'C' && ch != 'T')
    {
        throw "invalied input\n";
    }
}

inline char Nucleotide::flip()
{
    const char temp = c;

    switch (temp){
        case 'A':return 'T';
        case 'T':return 'A';
        case 'C':return 'G';
        case 'G':return 'C';
    }
    return temp;
}

#endif //DNA_NUCLEOTIDE_H
