//
// Created by Roderik Bauhn on 2016-04-12.
//

#ifndef ASSIGNMENTB_REGISTER_H
#define ASSIGNMENTB_REGISTER_H

#include "AirInstrument.h"
#include "StringInstrument.h"
class Register
{
private:
    //manages two subclasses.
    Instrument** InstrumentLista;
    //data
    int antalInstrument, capacitet;
public:
    Register();
    Register(int capacitet);
    //copy construct
    Register(const Register& orgin);
    ~Register();
    //assignment
    Register& operator=(const Register& orgin);
    //array expansion. used with A
    void expand();
    //A.  create obj of sub class
    void nyttLuftInstrument(string namn, bool trablas, bool blackblas);
    //A.   create obj of sub class
    void nyttStrangInstrument(string namn, int numberOfStrings, bool knapp, bool stroke );
    //B. getter
    int antaletInstrument(void)const;
    //B.  fills array with two subclass data
    void AllaInstrument(string array[]);
    //C.  getter
    int antalStrangInstrument(void)const;
    //C.  fills array with subclass data
    void AllaStrangInstrument(string array[]);

    //D. getter
    int antalLuftInstrument(void)const;
    //D. fills array with subclass data
    void AllaLuftInstrument(string array[]);
    // E. limit data output from subclass
    string AllstrangInstrumentInIntervall(int start, int end);
    //F  change data by sorting with key.
    void changeNrOfStrings(int nrOfStrings, string namn);
    // G. remove obj by key.
    void rmInstrument(const string Instrumentnamn);


};
#endif //ASSIGNMENTB_REGISTER_H_H
