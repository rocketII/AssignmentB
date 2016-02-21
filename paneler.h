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
		bool painted;
		
	public:
		//construct
		paneler(float prisPerMeter, string dimension, string Profile, bool painted);
		//destruct
		~paneler();
		//copy construct
                paneler(const paneler &origin);
		//assignment op the return is used for the followin statements to work. a=b=c (without the return reference it wouldn't work)
                paneler& operator=(const paneler &origin);
		// 2 cpp file 
		//get all data to std::string
		string toStringSpec()const;
		//get and set functions
		bool setProfile(string profile);
		bool setPainted(bool painted);
		string getProfile()const;
		bool getPainted()const;
		
		
};


#endif /* RAMAR_H */

