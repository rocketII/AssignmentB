/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<sstream>

#include "reglar.h"
//iosteam for debug
#include <iostream>
using namespace std;

reglar::reglar(float prisPerMeter, string dimension, string klassificering):virke(prisPerMeter,dimension)
{
	cout << "Hi! I'm reglar constructor "<<endl;
	this->klassificering=klassificering;
	cout << "Hi! I'm reglar constructor."<<" klassificering="<<klassificering <<" this->klassificering="<<this->klassificering <<endl;
}

	//copy construct
reglar::reglar(const reglar &origin):virke(origin)
{
	cout << "Hi! I'm reglar copy constructor" <<endl;
	this->klassificering=origin.klassificering;
	cout << "Hi! I'm reglar cpy construct. done here."<<" origin.klassificering="<<origin.klassificering<<" this got"<<this->klassificering<<endl;
}
        //assignment op
reglar& reglar::operator=(const reglar &origin)
{
    if(this != &origin)
    {
	cout << "Hi! I'm reglar = operator and this != &origin passed the if statement" <<endl;
        virke::operator =(origin);
        this->klassificering=origin.klassificering;
	cout << "Hi! I'm reglar = operator."<<" klassificering="<<klassificering <<" this->klassificering="<<this->klassificering <<endl;
    }
    cout << "I'm reglar = operator. Done now." <<endl;
    return *this;
}

string reglar::toStringSpec()const
{
	cout<<"I'm reglar toStringSpec"<<endl;
	cout << "Hi! I'm reglar toStringSpec()."<<" this->klassificering="<<this->klassificering <<endl;
	stringstream dd;
	dd << " klassificering: " << this->klassificering <<". ";
	cout <<"reglar In toStringSpec() dd.str(). " << dd.str()<<".";
	return dd.str();
}
	//get and set functions
bool reglar::setKlassificering(string klassificering )
{
	bool flag=false;
	cout<<"Reglar set()"<<endl;
	cout<<"Reglar set()"<<endl;
	this->klassificering=klassificering;
	cout << "Hi! I'm reglar and I alredy assigned klassificering " << this->klassificering <<endl;
	flag=true;
	return flag;
}

string reglar::getKlassificering()const
{
	cout << "Hi! I'm reglar I'm going to return klassificering." <<endl;
	cout <<"this->klassificering="<<this->klassificering<<"."<<endl;
	return this->klassificering;
}