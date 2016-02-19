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

#ifndef VIRKE_H
#define VIRKE_H
#include <string>
using namespace std;
class virke
{
private:
	float prisPerMeter;
	string dimension;
	
	
public:
	//construct
	virke(float prisPerMeter, string dimension);
	//copy construct
	virke(const virke &origin);
	//destruct virtual
	//assignment op
	virtual ~virke();
	string tostring()const;
	virtual string toStringSpec()=0;
	void setPrisPerMeter(float prisPerMeter);
	void setDimension(string dimension);
	
};


#endif /* VIRKE_H */

