
#include "paneler.h"
#include<sstream>
//iostream debug only!!!
//#include<iostream>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
using namespace std;
//construct
paneler::paneler(float prisPerMeter, string dimension, string Profile, bool painted):virke(prisPerMeter, dimension)
{
	//cout << "Hi! I'm paneler constructor" <<endl;
	this->Profile=Profile;
	this->painted=painted;
	//cout << "Hi! I'm paneler constructor. profile: " << Profile <<" painted" << painted<<" this->Profile: "<< this->Profile<< " this->painted: "<<this->painted<<endl;
	//cout << "Hi! I'm paneler constructor. I'm done." <<endl;
    
}
		//destruct
paneler::~paneler()
{
    //cout << "Hi! I'm paneler destructor. I do null" <<endl;
}
		//copy construct
paneler::paneler(const paneler &origin):virke(origin)
{
	//cout << "Hi! I'm paneler copy constructor" <<endl;
	this->Profile=origin.Profile;
	this->painted=origin.painted;
	//cout << "Hi! I'm paneler copy constructor. And I'm done with: " <<origin.Profile <<" "<< origin.painted<<endl;
}
		//assignment op the return is used for the followin statements to work. a=b=c (without the return reference it wouldn't work)
paneler& paneler::operator=(const paneler &origin)
{
	//cout << "Hi! I'm paneler = operator" <<endl;
	if(this != &origin)
	{
		//cout << "Hi! I'm paneler = operator. We passed the this != &origin" <<endl;
		virke::operator =(origin);
		this->Profile=origin.Profile;
		this->painted=origin.painted;
		//cout << "Hi! I'm paneler = operator. succes in" << origin.Profile<<" "<<origin.painted<<endl;
	}
	//cout << "Hi! I'm paneler = operator. I'm done here." <<endl;
	return *this;
}
		// 2 cpp file 
		//get all data to std::string
string paneler::toStringSpec()const
{
	//cout << "Hi! I'm paneler. in toStringSpec() now. " <<endl;
	stringstream cc;
	cc << " Profile: " << this->Profile <<" Painted? " << this->painted <<". ";
	//cout << "Hi! I'm paneler in tostringSpec() I'm done." <<endl;
	return cc.str();
}
		//get and set functions
bool paneler::setProfile(string profile)
{
	//cout << "Hi! I'm paneler in setProfile()."<<endl;
	this->Profile=profile;
	//cout << "Hi! I'm paneler in setProfile(). Done with "<<profile << " this->"<<this->Profile<<endl;
	return true;
}

bool paneler::setPainted(bool painted)
{
	//cout << "Hi! I'm paneler in setPainted()."<<endl;
	this->painted=painted;
	//cout << "Hi! I'm paneler in setPainted(). Done with: "<<painted << " this->"<<this->painted<<endl;
	return true;
}

string paneler::getProfile()const
{
	//cout << "Hi! I'm paneler in getProfile()"<<endl;
	//cout << "Hi! I'm paneler in getProfile(). Returning: "<<" this->"<<this->Profile<<endl;
	return this->Profile;
}

bool paneler::getPainted()const
{
	//cout << "Hi! I'm paneler in getPainted()."<<endl;
	//cout << "Hi! I'm paneler in getPainted(). Returning: "<<" this->"<<this->painted<<endl;
	return this->painted;
}