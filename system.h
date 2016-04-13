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
    void addMotionar(void)const;
	void addProffs(void)const;
    void toString_registerData(void);
    int getNrOfPlayers(void)const;
    void toString_proPlayers(void)const;
    int getNrOfProPlayers(void)const;
    void toString_motionarPlayers(void)const;
    int getNrOfMotionarer(void)const;
    void rmPlayer(void)const;
    void changeProPlayerYearInService(void)const;
    void sortPlayersByNames(void)const;

public:
	System(void);
	~System(void);

	void menu(void);
	
};

