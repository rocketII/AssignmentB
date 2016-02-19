/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bps
 *
 * Created on den 15 februari 2016, 20:15
 */

#include <cstdlib>
#include"TestVirkeManager.h"
#include "virkemanager.h"
using namespace std;

/*
 * 
 */
void menuInit(Virkemanager &butik);
void addVirke(Virkemanager &butik);
void addRamar(Virkemanager &butik);
void addPaneler(Virkemanager &butik);
void removeVirke(string Dimension, float price);
void AllDataVirke(Virkemanager &butik);
void AllDataRamar(Virkemanager &butik);
void AllDataPaneler(Virkemanager &butik);
void NumberOfVirke(Virkemanager &butik);
void NumberOfRamar(Virkemanager &butik);
void NumberOfPaneler(Virkemanager &butik);

int main(int argc, char** argv)
{
	bool flag = false;
	Virkemanager butik;
	do
	{
		menuInit(butik);
	}
	while(!flag);

	return 0;
}
bool menuInit(Virkemanager &butik)
{
	bool flag = false;
	string choice;
	void menuInit();
	cout << "A. addVirke\n B. addRamar\n C. addPaneler\nD. removeVirke  \nE. AllDataVirke \nF.AllDataRamar \nG. AllDataPaneler \nH. NumberOfVirke \nI. NumberOfRamar \nJ.NumberOfPaneler" << endl;
	cout << "Just pressing enter Exit this program\nChoice:"<<endl;
	switch(choice)
	{
	case 'A':
		break;
	case 'B':
		break;
		case 'C':
		break;
		case 'D':
		break;
		case 'E':
		break;
		case 'F':
		break;
		case 'G':
		break;
		case 'H':
		break;
		case 'I':
		break;
		case 'J ':
		break;
	default:
		break;
	}
	return flag;
}
void addVirke(Virkemanager &butik)
{
    
	
}
void addRamar(Virkemanager &butik)
{
	
}
void addPaneler(Virkemanager &butik)
{
	
}
void removeVirke(Virkemanager &butik)
{
	
}
void AllDataVirke(Virkemanager &butik)
{
	
}
void AllDataRamar(Virkemanager &butik)
{
	
}
void AllDataPaneler(Virkemanager &butik)
{
	
}
void NumberOfVirke(Virkemanager &butik)
{
	
}
void NumberOfRamar(Virkemanager &butik)
{
	
}
void NumberOfPaneler(Virkemanager &butik)
{
	
}

