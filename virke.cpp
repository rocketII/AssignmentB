/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include<sstream>
#include "virke.h"
using namespace std;

//construct
virke::virke(float prisPerMeter, string dimension)
{
    this->prisPerMeter=prisPerMeter;
    this->dimension=dimension;
}
	//copy construct
virke::virke(const virke &origin)
{
    this->dimension=origin.dimension;
    this->prisPerMeter=origin.prisPerMeter;
    
}
	//destruct virtual
	//assignment op
virke& virke::operator=(const virke &origin)
{
    //only do operation if there's an diff in values for the objs reference.
    if(this != &origin)
    {
        this->dimension=origin.dimension;
        this->prisPerMeter=origin.prisPerMeter;
    }
    return *this;
}
virke::~virke()
{
    ;
}
string virke::tostring()const
{
    stringstream ss, aa, bb;
    ss <<"dimension: " << this->dimension << "pris/meter: " << this->prisPerMeter << "\n";
    aa << this->toStringSpec() << "\n";
    bb << ss << aa << endl;
    return bb.str();
}
void virke::setPrisPerMeter(float prisPerMeter)
{
    this->prisPerMeter=prisPerMeter;
}
void virke::setDimension(string dimension)
{
    this->dimension=dimension;
}