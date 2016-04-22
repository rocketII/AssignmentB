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
    deltagare** deltagarLista;
    int antalDeltagare, capacitet;
    void quickSort(Register& orgin, int start, int end);
    int partition(Register& orgin, int start, int end);
    void swapI(Register& source,int index1, Register& orgin , int index2);
public:
    Register();
    Register(int capacitet);
    Register(const Register& orgin);
    ~Register();
    Register& operator=(const Register& orgin);
    bool operator<(const Register& orgin);
    void expand();
    void nyProfessionellDeltagare(string namn, string kon, string klubb, int aktivaPerioder);
    void nyMotionarDeltagare(string namn, string kon, int gammal);
    int antaletDeltagare(void)const;
    int antalProffs(void)const;
    int antalMotionarer(void)const;
    void AllaDeltagare(string array[]);
    void AllaMotionarer(string array[]);
    void AllaProffs(string array[]);
    void rmDeltagare(const string Uniktnamn);
    void setProffsActiveYears(int yearInService, string namn);
    void sortingByNames(void);

    //int getProffsActiveYears(string namn); Debug mode only!!!
};
#endif //ASSIGNMENTB_REGISTER_H_H
