/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reglar.h
 * Author: bps
 *
 * Created on den 17 februari 2016, 13:17
 */

#ifndef REGLAR_H
#define REGLAR_H
#include"virke.h"
//Är basklass
//ska ha abstraktion och virtuealitet.
class reglar : public virke
{
private:
	string klassificering;
public:
	reglar(float prisPerMeter, string dimension, string klassificering);
	//in cpp reglar(float prisPerMeter, string dimension, string klassificering):virke(prisPerMeter,dimension){}
	//copy construct
        reglar(const reglar &origin);
        //assignment op reglar& so we can do asignment chan. for example a=b=c;
        reglar& operator=(const reglar &origin);
	string toStringSpec()const;
	//get and set functions
	bool setKlassificering(string klassificering );
	string getKlassificering()const;
	
};


#endif /* REGLAR_H */

