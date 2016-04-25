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
    //1.
    void nyttLuftInstrument(string namn, bool trablas, bool blackblas);
    //1.
    void nyttStrangInstrument(string namn, int numberOfStrings, bool knapp, bool stroke );
    //2.
    int antaletInstrument(void)const;
    //2.
    void AllaInstrument(string array[]);
    //3.
    int antalStrangInstrument(void)const;
    //3.
    void AllaStrangInstrument(string array[]);

    //4.
    int antalLuftInstrument(void)const;
    //4.
    void AllaLuftInstrument(string array[]);
    // 5.
    string AllstrangInstrumentInIntervall(int start, int end);
    //6
    void changeNrOfStrings(int nrOfStrings, string namn);
    // 7.
    void rmInstrument(const string Instrumentnamn);

    //int getProffsActiveYears(string namn); Debug mode only!!!
};
#endif //ASSIGNMENTB_REGISTER_H_H
