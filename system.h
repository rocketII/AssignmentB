#pragma once
#include "register.h"
#include<iostream>
#include<string>
using namespace std;
class System
{
private:
	/* motionar == stringInstrument
	 * cout<<"A: Lägga till instrument.\n"
    <<"B: Presentera alla instrument.\n"
    <<"C: Presentera alla stränginstrument med all tillhörande information.\n"
    <<"D: Presentera alla blåsinstrument med all tillhörande information.\n"
    <<"E: Presentera alla stränginstrument vars strängantal ligger i ett givet intervall.\n"
    <<"F: Ändra antal strängar givet stränginstrumentets namn.\n"
    <<"G: Ta bort ett instrument.\n"
    <<"H: Exit.\n"
    <<endl;
	 * */
	string *ptr;
	Register instance;
	void menutxt(void)const;
    //A
    void addInstrument(void);
    //A.
    void addStringInstrument(void);
    //A.
	void addAirInstrument(void);
    //B.
    void toString_InstrumentData(void);
    //B.
    int getNrOfInstruments(void)const;
    //C.
    void toString_StringInstruments(void);
    //C..
    int getNrOfStringInstruments(void)const;
    //D.
    void toString_luftInstrument(void);
    //D.
    int getNrOfLuftInstrument(void)const;
    //E.
    void getStringInstrumentWithinIntervall(void);
    //F.
    void findInstrumentChangeNrOfStrings(void);
    //G.
    void rmPlayer(void);



public:
	System(void);
	~System(void);
	void menu(void);
};

