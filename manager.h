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
#include"virke.h"
class manager
{
private:
	virke **ptr2ArrayWithVirkePtr;
	int numberOfReglar, numberOfPaneler;
public:
        manager();
	~manager();
	manager(const manager &origin);
	manager& operator=(const manager &origin);
	bool newPanel(string dimension, float prisPerMeter, string profile, bool painted);
	bool newRegel(string dimension, float prisPerMeter, string klassificering);
	bool changePaintedStatus(string dimension, string profile);
	string AllDataVirke();
	string AllDataRamar();
	string AllDataPaneler();
	int numberOfReglar();
	int numberOfPaneler();
};

#endif /* MANAGER_H */

