/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include<sstream>
#include "virke.h"
//debug only
#include<iostream>
using namespace std;

//construct
virke::virke(float prisPerMeter, string dimension)
{
	cout << "Hi! I'm virke constructor."<<endl;
	cout << "Hi! I'm virke constructor."<<" price:"<<prisPerMeter<<" dimension:"<<dimension<<endl;
	this->prisPerMeter=prisPerMeter;
	this->dimension=dimension;
	cout << "Hi! I'm virke constructor. Done that. "<<" this->prisPerMeter="<< this->prisPerMeter<<" this->dimension=" << this->dimension<<"."<<endl;
}
	//copy construct
virke::virke(const virke &origin)
{
	cout << "Hi! I'm virke copy constructor."<<"origin.dimension="<<origin.dimension<<". origin.prisPerMeter="<<origin.prisPerMeter<<"."<<endl;
	this->dimension=origin.dimension;
	this->prisPerMeter=origin.prisPerMeter;
	cout << "Hi! I'm virke copy constructor."<<"this->dimension="<<this->dimension<<". this->prisPerMeter="<<this->prisPerMeter<<"."<<endl;
}
	//destruct virtual
	//assignment op
virke& virke::operator=(const virke &origin)
{
	cout <<"I'm virke = op."<<endl;
	//only do operation if there's an diff in values for the objs reference.
	if(this != &origin)
	{
		cout<<"I'm virke = op. if statement==true";
		cout <<"I'm virke = op. going to work with. "<<"origin.dimension="<<origin.dimension<<". And origin.prisPerMeter="<< origin.prisPerMeter<<"."<<endl;
		this->dimension=origin.dimension;
		this->prisPerMeter=origin.prisPerMeter;
		cout <<"I'm virke = op. this asignment done. "<<"this->dimension="<<this->dimension<<". And this->prisPerMeter="<< this->prisPerMeter<<"."<<endl;
	}
	cout <<"I'm virke = op. Done!!"<<endl;
	return *this;
}
virke::~virke()
{
	cout <<"Hi! I'm Virke destructor. Nothing 2 do."<<endl;
}
string virke::tostring()const
{
	cout <<"virke toString()"<<endl;
	stringstream ss, aa, bb;
	ss <<"dimension: " << this->getDimension() << "pris/meter: " << this->getPrisPerMeter();
	cout <<"virke toString(). ss got: "<<ss.str()<<"."<<endl;
	aa << this->toStringSpec();
	cout <<"virke toString(). aa got(toStringSpec): "<<aa.str()<<"."<<endl;
	bb << ss.str() << aa.str() << endl;
	cout <<"virke toString(). bb got(ss+aa): "<<bb.str()<<"."<<endl;
	cout <<"virke toString(). returning bb.str()"<<endl;
	return bb.str();
	//return "ok";
}
void virke::setPrisPerMeter(float prisPerMeter)
{
	cout <<"virke setPrisPerMeter() "<<endl;
	cout<<"virke. setPrisPerMeter. work with prisPerMeter="<<prisPerMeter<<endl;
	this->prisPerMeter=prisPerMeter;
	cout<<"virke. setPrisPerMeter.I'm done! worked with this->prisPerMeter="<<this->prisPerMeter<<endl;
}
void virke::setDimension(string dimension)
{
	cout <<"virke setDimension() "<<endl;
	cout<<"virke. Dimension. work with dimension="<<dimension<<endl;
	this->dimension=dimension;
	cout<<"virke. setdimension().I'm done! worked with this->dimension="<<this->dimension<<endl;
}
float virke::getPrisPerMeter()const
{
	cout <<"virke getPrisPerMeter() "<<endl;
	cout <<"virke setPrisPerMeter(). returning: "<< this->prisPerMeter<<endl;
	return this->prisPerMeter;
}
string virke::getDimension()const
{
	cout <<"virke getDimension()"<<endl;
	cout <<"virke getDimension(). returning "<< this->dimension <<endl;
	return this->dimension;
}