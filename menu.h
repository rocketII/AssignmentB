/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu.h
 * Author: bps
 *
 * Created on den 19 februari 2016, 08:56
 */

#ifndef MENU_H
#define MENU_H
#include "virkemanager.h"
class menu
{
private:
public:
	bool menuInit();
	bool addVirke();
	bool addRamar();
	bool addPaneler();
	bool removeVirke(string Dimension, float price);
	bool AllDataVirke();
	bool AllDataRamar();
	bool AllDataPaneler();
	bool NumberOfVirke();
	bool NumberOfRamar();
	bool NumberOfPaneler();
	
};


#endif /* MENU_H */

