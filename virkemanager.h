/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   manager.h
 * Author: bps
 *
 * Created on den 19 februari 2016, 08:55
 */

#ifndef MANAGER_H
#define MANAGER_H
#include"paneler.h"
#include"reglar.h"
//becuse class virke are abstract it cannot be objectified
//this class aka container class for virke and
class Virkemanager
{
private:
	virke **ptr2ArrayWithVirkePtr;
	int numberOfReglar, numberOfPaneler, numberOfVirke;
	string virkeDataTmpCache;
public:
	//construct
        Virkemanager();
	
	//destruct
	~Virkemanager();
	
	//construct with same class obj, aka copy construct
	Virkemanager(const Virkemanager &origin);
	
	//overiding the '=' operator
	Virkemanager& operator=(const Virkemanager &origin);
	bool newPanel(string dimension, float prisPerMeter, string profile, bool painted);
	bool newRegel(string dimension, float prisPerMeter, string klassificering);
	bool changePaintedStatus(string dimension, string profile);
	
	
	string AllDataVirke();
	string AllDataRamar();
	string AllDataPaneler();
	bool removeVirke(float price, string dimension);
	
	//numberOf used with changing string array holder of virke data.
	int numberOfReglar();
	int numberOfPaneler();
	
};

#endif /* MANAGER_H */

