/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ramar.h
 * Author: bps
 *
 * Created on den 17 februari 2016, 13:16
 */

#ifndef PANELER_H
#define PANELER_H
#include"virke.h"
class paneler: public virke
{
	private:
		string Profile;
		bool painted();
		
	public:
		//ramar();
		paneler(float prisPerMeter, string dimension, string Profile, bool painted);panelerpaneler(){};
		string toStringSpec();
		
		
};


#endif /* RAMAR_H */

