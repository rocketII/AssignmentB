
#include "paneler.h"
#include<sstream>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
using namespace std;
//construct
paneler::paneler(float prisPerMeter, string dimension, string Profile, bool painted):virke(prisPerMeter, dimension)
{
    this->Profile=Profile;
    this->painted=painted;
}
		//destruct
paneler::~paneler()
{
    ;
}
		//copy construct
paneler::paneler(const paneler &origin):virke(origin)
{
    this->Profile=origin.Profile;
    this->painted=origin.painted;
    
    
}
		//assignment op the return is used for the followin statements to work. a=b=c (without the return reference it wouldn't work)
paneler& paneler::operator=(const paneler &origin)
{
    if(this != &origin)
    {
        virke::operator =(origin);
        this->Profile=origin.Profile;
        this->painted=origin.painted;
    }
    return *this;
}
		// 2 cpp file 
		//get all data to std::string
string paneler::toStringSpec()const
{
    stringstream cc;
    cc << "Profile: " << this->Profile <<" Painted? " << this->painted <<"."<< endl;
    return cc.str();
}
		//get and set functions
bool paneler::setProfile(string profile)
{
    this->Profile=profile;
    return true;
}

bool paneler::setPainted(bool painted)
{
    this->painted=painted;
    return true;
}

string paneler::getProfile()const
{
    return this->Profile;
}

bool paneler::getPainted()const
{
    return this->painted;
}