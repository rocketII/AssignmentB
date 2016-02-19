/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<typeinfo>

#include "virkemanager.h"
using namespace std;

//construct
Virkemanager::Virkemanager()
{
    this->ptr2ArrayWithVirkePtr= new virke*[2];
    this->counterVirke=0;
    this->virkeDataTmpCache="currently empty";
}
	
	//destruct
Virkemanager::~Virkemanager()
{
    
    
}
	
	//construct with same class obj, aka copy construct
Virkemanager::Virkemanager(const Virkemanager &origin)
{
    ;
}
	
	//overiding the '=' operator
Virkemanager& Virkemanager::operator=(const Virkemanager &origin)
{
    
}
bool Virkemanager::newPanel(string dimension, float prisPerMeter, string profile, bool painted)
{
    
}
bool Virkemanager::newRegel(string dimension, float prisPerMeter, string klassificering)
{
    
}
bool Virkemanager::changePaintedStatus(string dimension, string profile)
{
            
}
		
string Virkemanager::AllDataVirke()
{
    
}
string Virkemanager::AllDataRamar()
{
    
}
string Virkemanager::AllDataPaneler()
{
    
}        
bool Virkemanager::removeVirke(float price, string dimension)
{
    
}
	
	//numberOf used with changing string array holder of virke data.
int Virkemanager::numberOfReglar()
{
    
}
int Virkemanager::numberOfPaneler()
{
    
}