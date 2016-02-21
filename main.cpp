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
*/
void AllDataVirke(Virkemanager &butik);
void AllDataReglar(Virkemanager &butik);
void AllDataPaneler(Virkemanager &butik);

int main(int argc, char** argv)
{
	//lets test that virkemanager works when it comes down to: constructing, copyconstruct, assignment operator, destruction.
	//And no memleaks happens.
	cout << "gonna try testing the mechanics..." << endl;
	testSuitVirkeManager();
	//*/
	cout << "Starting menu\n Welcome to Timber management 2016 <command prompt ver.> "<<endl;
	bool flag = false;
	Virkemanager butik;
	do
	{
		menuInit(butik);
	}
	while(!flag);
	 
	//*/
	return 0;
}
//*
bool menuInit(Virkemanager &butik)
{
	/*
	 * 
	A. bool newPanel(string dimension, float prisPerMeter, string profile, bool painted)
	B. bool newRegel(string dimension, float prisPerMeter, string klassificering)
	C. bool changePaintedStatus(string dimension, string profile)
	D. string& AllDataVirke()
	E.string& AllDataReglar()
	F.string& AllDataPaneler()
	G.bool removeVirke(float price, string dimension)
	H.int getcounterVirke()
	(int getvirkeArrayCapacity())
	I.int getNumberOfReglar()
	J.int getNumberOfPaneler()
	 
	
	*/
	
	bool flag = false;
	string dimension;
	float prisPerMeter;
	string profil;
	string choice;
	string klassificering = "default value";
	std::cout << "A. Add Panel\nB. Add Regel\nC. Change basepainted with given dimension and profile\nD. Print all data\nE. print all data of type Regler\nF. print all data of type paneler\nG. Remove Timber of given price and dimension\nH. Get total number of timber\nI. Get number of Regler\nJ. Get number of Paneler.\n" << endl;
	cout << "Just pressing enter Exit this program\nChoice:"<<endl;
	switch(choice)
	{
	case 'A':
		dimension="10x10"; 
		prisPerMeter=10.00;
		profil="Bas";
		cout << "Dimension: ";
		cin >> dimension;
		cin.ignore();
		cout << "Price/meter: ";
		cin >> prisPerMeter;
		cin.ignore();
		cout << "Profile: ";
		cin >> profil;
		cin.ignore();
		cout << "Are the panel base painted?: ";
		cin >> choice;
		cin.ignore();
		butik.newPanel(dimension, prisPerMeter,profil, basePaintedChoice(choice));
		break;
	case 'B':
		
		cout << "Dimension: ";
		cin >> dimension;
		cin.ignore();
		cout << "price/meter: ";
		cin >> prisPerMeter ;
		cin.ignore();
		cout << "clasification: ";
		cin >> klassificering;
		cin.ignore();
		butik.newRegel(dimension, prisPerMeter, klassificering);
		break;
	case 'C':
		cout << "Dimension: ";
		cin >> dimension;
		cin.ignore();
		cout << "Profile: ";
		cin >> profil;
		cin.ignore();
		butik.changePaintedStatus(dimension, profil);
		break;
	case 'D':
		AllDataVirke(butik);
		break;
	case 'E':
		AllDataReglar(butik);
		break;
	case 'F':
		AllDataPaneler(butik);
		break;
	case 'G':
		cout << "Price/meter: ";
		cin >> prisPerMeter;
		cin.ignore();
		cout << "Dimension: ";
		cin >> dimension;
		cin.ignore();
		butik.removeVirke(prisPerMeter, dimension);
		break;
	case 'H':
		cout << "You got " << butik.getcounterVirke() <<" object in store"<<endl;
		break;
	case 'I':
		cout << "You got " << butik.getNumberOfReglar() <<" object in store of type reglar"<<endl;
		break;
	case 'J':
		cout << "You got " << butik.getNumberOfPaneler() <<" object in store of type paneler"<<endl;
		break;
	default:
		cout << "you or someting typed out of bound. Chose item from menu in capital letter" << endl;
		break;
	}
	return flag;
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
void AllDataVirke(Virkemanager &butik)
{
	string *printRes= new string[butik.getcounterVirke()];
	printRes=butik.AllDataVirke();
	for(int i= 0; i < butik.getcounterVirke(); i++)
	{
		cout << printRes[i];
	}
}
void AllDataReglar(Virkemanager &butik)
{
	string *printRes= new string[butik.getNumberOfReglar()];
	printRes=butik.AllDataVirke();
	for(int i= 0; i < butik.getNumberOfReglar(); i++)
	{
		cout << printRes[i];
	}
}
void AllDataPaneler(Virkemanager &butik)
{
	string *printRes= new string[butik.getNumberOfPaneler()];
	printRes=butik.AllDataVirke();
	for(int i= 0; i < butik.getNumberOfPaneler(); i++)
	{
		cout << printRes[i];
	}
}
//*/