/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<sstream>

#include "reglar.h"
using namespace std;

reglar::reglar(float prisPerMeter, string dimension, string klassificering):virke(prisPerMeter,dimension)
{
    this->klassificering=klassificering;
}
	//copy construct
reglar::reglar(const reglar &origin):virke(origin)
{
    this->klassificering=origin.klassificering;
}
        //assignment op
reglar& reglar::operator=(const reglar &origin)
{
    if(this != &origin)
    {
        virke::operator =(origin);
        this->klassificering=origin.klassificering;
    }
    return *origin;
}

string reglar::toStringSpec()const
{
    stringstream dd;
    dd << "klassificering: " << this->klassificering <<"."<< endl;
}
	//get and set functions
bool reglar::setKlassificering(string klassificering )
{
    this->klassificering=klassificering;
}

string reglar::getKlassificering()
{
    return this->klassificering;
}