//
// Created by cglick on 12/27/18.
//

#ifndef UNTITLED1_IDNA_H
#define UNTITLED1_IDNA_H

class IDna
{
public:
    virtual Nucleotide & operator[](size_t index) const = 0;
    virtual size_t sequence_length() const = 0;
    virtual ~IDna();
};

#endif //UNTITLED1_IDNA_H
