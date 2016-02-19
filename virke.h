/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   virke.h
 * Author: bps
 *Base class for reglar and ramar
 * Created on den 17 februari 2016, 13:16
 */
#include <string>
#ifndef VIRKE_H
#define VIRKE_H
using namespace std;
class virke
{
private:
	float prisPerMeter;
	string dimension;
	
	
public:
	virke();
	virke(float prisPerMeter, string dimension);
	virke(const virke &origin);
	virtual ~virke();
	string tostring();
	virtual string toStringSpec();
	void setPrisPerMeter(float prisPerMeter);
	void setDimension(string dimension);
	
};


#endif /* VIRKE_H */

