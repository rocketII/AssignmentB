#pragma once
#include "register.h"
#include<iostream>
#include<string>
using namespace std;
class System
{
private:
	string *ptr;
	Register instance;
	void menutxt(void)const;
    void addMotionar(void);
	void addProffs(void);
    void toString_registerData(void);
    int getNrOfPlayers(void)const;
    void toString_proPlayers(void);
    int getNrOfProPlayers(void)const;
    void toString_motionarPlayers(void);
    int getNrOfMotionarer(void)const;
    void rmPlayer(void);
    void changeProPlayerYearInService(void);
    void sortPlayersByNames(void);

public:
	System(void);
	~System(void);
	void menu(void);
};

