#include <iostream>
#include "model/DnaSequence.h"
#include "model/DnaWriter.h"
#include "model/DnaReaderText.h"
#include "view/Cmd.h"
#include <string>
using std::cout;
using std::endl;
using std::ostream;

void check_charPtr_ctor()
{
    try
    {
        DnaSequence dnaSequence("AGT");
    }
    catch (char const * s)
    {
        cout<<s<<endl;
        cout<<"ERROR IN chack_string_ctor FUNCTION";

    }

}

void check_string_ctor()
{
    try
    {
        std::string seq="AGT";
        DnaSequence dnaSequence(seq);
    }
    catch(char const * s)
    {
        cout<<s<<endl;
        cout<<"ERROR IN chack_charPtr_ctor FUNCTION";
    }

}
void check_copy_ctor()
{
    try
    {
        std::string seq="AGT";
        DnaSequence dnaSequence1(seq);
        DnaSequence dnaSequence2(dnaSequence1);
    }
    catch(char const * s)
    {
        cout<<s<<endl;
        cout<<"ERROR IN chack_copy_ctor FUNCTION";

    }

}

void check_index_operator()
{
    try
    {
        DnaSequence dnaSequence("AGT");
        if(!(dnaSequence[1] == 'G'))
        {
            throw "ERROR IN chack_index_operator FUNCTION";
        }
    }
    catch(char const * s)
    {
        cout<<s<<endl;
        cout<<"ERROR IN chack_index_operator FUNCTION";

    }



}

void check_equal_operators()
{
    try {
        DnaSequence dnaSequence1("AGT");
        DnaSequence dnaSequence2("AGT");

        if (!(dnaSequence1 == dnaSequence2))
        {
            throw "Comparison Error";
        }
        if(dnaSequence1 != dnaSequence2)
        {
            throw "Comparison Error";
        }
    }
    catch(char const * s)
    {
        cout<<s<<endl;
        cout<<"ERROR IN chack_equal_operators FUNCTION";

    }

}

void check_assignment_operators()
{
    DnaSequence dnaSequence("AGTAGTAGTAGT");
    dnaSequence="AAA";
    std::string seq1 = "AAA";
    dnaSequence=seq1;
    DnaSequence dnaSequence2("GGG");
    dnaSequence2=dnaSequence;


}


void check_slicing()
{
    try{

        DnaSequence dnaSequence("AGTAGT");
        if('G'==dnaSequence[1])
        {
            cout<<"good\n";
        }
        else
        {
            cout<<"bad\n";
        }
        DnaSequence slice_dnaSequence("AGT");
        if(!(dnaSequence.get_slice(0,3)==slice_dnaSequence))
        {
            throw "problem in pairing function\n";
        }

    }
    catch (char const * s)
    {
        cout<<s;
    }
}

void check_writing_dna_to_file()
{
    try
    {
        DnaWriter dnaWriter("obj1.txt");
        DnaSequence dnaSequence("AGTAGT");
        dnaWriter.write(dnaSequence);
    }
    catch (std::runtime_error r)
    {
        cout<<r.what();
    }

}
void check_reading_dna_from_file(){
    try
    {
        DnaReaderText dnaReaderText("obj1.txt");
        DnaSequence dnaSequence = dnaReaderText.read();


    }
    catch (std::runtime_error r)
    {
        cout<<r.what();
    }
}
void check_paring(){
    try{
        DnaSequence dnaSequence("AGTCGG");
        DnaSequence paringDnaSquence = dnaSequence.paring();

    }
    catch (char const * c)
    {
        cout<<c;
    }
    catch (std::runtime_error r)
    {
        cout<<r.what();
    }
}
void check_operator_ostream(){

     DnaSequence dnaSequence("AGTCGG");
     cout<<dnaSequence;
}

void check_cmd()
{
    UI * ui = new Cmd();
    ui->run();
}

int main()
{

    /*check_charPtr_ctor();
    check_string_ctor();
    check_copy_ctor();
    check_index_operator();
    check_assignment_operators();
    check_equal_operators();
    check_slicing();
    check_writing_dna_to_file();
    check_reading_dna_from_file();
    check_paring();
    check_operator_ostream();
*/
    check_cmd();


    return 0;
}
