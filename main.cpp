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
#include <iostream>
#include"TestVirkeManager.h"
#include "virkemanager.h"

using namespace std;

/*
 * 
 *
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
bool basePaintedChoice(string choice);
*/
int main(int argc, char** argv)
{
	//lets test that virkemanager works when it comes down to: constructing, copyconstruct, assignment operator, destruction.
	//And no memleaks happens.
	cout << "gonna try testing the mechanics..." << endl;
	testSuitVirkeManager();
	/*bool flag = false;
	Virkemanager butik;
	do
	{
		menuInit(butik);
	}
	while(!flag);
	* 
	*/
	return 0;
}
/*
bool menuInit(Virkemanager &butik)
{
	bool flag = false;
	string dimension;
	float prisPerMeter;
	string profil;
	string choice;
	string klassificering = "default value";
	std::cout << "A. addVirke\n B. addReglar\n C. addPaneler\nD. removeVirke  \nE. AllDataVirke \nF.AllDataRamar \nG. AllDataPaneler \nH. NumberOfVirke \nI. NumberOfRamar \nJ.NumberOfPaneler" << endl;
	cout << "Just pressing enter Exit this program\nChoice:"<<endl;
	switch(choice)
	{
	case 'A':
		
		break;
	case 'B':
		
		cout << "Ange Dimension för Regel: ";
		cin >> dimension;
		cin.ignore();
		cout << "Ange Pris per meter för Regel: ";
		cin >> prisPerMeter ;
		cin.ignore();
		cout << "Vad för klassificering gäller för Regel: ";
		cin >> klassificering;
		cin.ignore();
		butik.newRegel(dimension, prisPerMeter, klassificering);
		break;
	case 'C':
		
		cout << "Ange Dimension för Regel: ";
		cin >> dimension;
		cin.ignore();
		cout << "Ange Pris per meter för Regel: ";
		cin >> prisPerMeter ;
		cin.ignore();
		cout << "Vad för profil gäller för Regel: ";
		cin >> profil;
		cin.ignore();
		cout << "Är denna Regel grundmålad?(J eller N): ";
		cin >> choice;
		cin.ignore();
		butik.newPanel(dimension, prisPerMeter,profil, basePaintedChoice(choice));
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
	case 'J':
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
bool basePaintedChoice(string choice)
{
	bool flag = false;
	if(choice[0] == 'J' || choice[0] == 'j')
	{
		flag = true;
	}
	return flag;
}
*/