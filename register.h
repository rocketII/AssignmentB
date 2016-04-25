//
// Created by root on 2016-04-12.
//

#ifndef ASSIGNMENTB_REGISTER_H
#define ASSIGNMENTB_REGISTER_H

#include "AirInstrument.h"
#include "StringInstrument.h"
class Register
{
private:
    Instrument** InstrumentLista;
    int antalInstrument, capacitet;
public:
    Register();
    Register(int capacitet);
    Register(const Register& orgin);
    ~Register();
    Register& operator=(const Register& orgin);
    void expand();
    //A.
    void nyttLuftInstrument(string namn, bool trablas, bool blackblas);
    //A.
    void nyttStrangInstrument(string namn, int numberOfStrings, bool knapp, bool stroke );
    //B.
    int antaletInstrument(void)const;
    //B.
    void AllaInstrument(string array[]);
    //C.
    int antalStrangInstrument(void)const;
    //C.
    void AllaStrangInstrument(string array[]);

    //D.
    int antalLuftInstrument(void)const;
    //D.
    void AllaLuftInstrument(string array[]);
    // E.
    string AllstrangInstrumentInIntervall(int start, int end);
    //F
    void changeNrOfStrings(int nrOfStrings, string namn);
    // G.
    void rmInstrument(const string Instrumentnamn);


};
#endif //ASSIGNMENTB_REGISTER_H_H
