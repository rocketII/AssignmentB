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
    this->virkeArrayCapacity=0;
    this->virkeDataTmpCache="currently empty";
}
	
	//destruct
Virkemanager::~Virkemanager()
{
    for(int i=0; i< this->counterVirke; i++)
    {
	delete this->ptr2ArrayWithVirkePtr[i];
    }
    delete [] this->ptr2ArrayWithVirkePtr;
    
}
	
	//construct with same class obj, aka copy construct
Virkemanager::Virkemanager(const Virkemanager &origin)
{
    this->counterVirke= origin.counterVirke;
    this->virkeArrayCapacity=origin.virkeArrayCapacity; // hur stor array man behöver för memalloc
    this->ptr2ArrayWithVirkePtr= new virke *[this->virkeArrayCapacity];
    for(int i=0; i < this->counterVirke; i++)
	{
                //check the origin element wise and look at each obj type paneler or reglar and alloc space for the obj type.
		if(typeid(*origin.ptr2ArrayWithVirkePtr[i])==typeid(paneler))
		{
			this->ptr2ArrayWithVirkePtr[i]= new paneler(*((paneler*)origin.ptr2ArrayWithVirkePtr[i])); 
		}
		else
		{
			this->ptr2ArrayWithVirkePtr[i]= new reglar(*((reglar*)origin.ptr2ArrayWithVirkePtr[i])); 
		}
	}
}
	
	//overiding the '=' operator
Virkemanager& Virkemanager::operator=(const Virkemanager &origin)
{
    if(this != &origin)
	{
		for(int i=0; i < this->counterVirke; i++)
		{
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		delete [] this->ptr2ArrayWithVirkePtr;
		
		this->counterVirke=origin.counterVirke;
		this->virkeArrayCapacity=origin.virkeArrayCapacity;
		this->ptr2ArrayWithVirkePtr= new virke *[this->virkeArrayCapacity];
		for(int i=0; i < this->counterVirke; i++)
		{
			
			if(typeid(*origin.ptr2ArrayWithVirkePtr[i])==typeid(reglar))
			{
				this->ptr2ArrayWithVirkePtr[i]=new reglar(*((reglar*)origin.ptr2ArrayWithVirkePtr[i]));
			}
			else
			{
				this->ptr2ArrayWithVirkePtr[i]=new paneler(*((paneler*)origin.ptr2ArrayWithVirkePtr[i]));
			}
			 
		}
	}
	return *this;
}
bool Virkemanager::newPanel(string dimension, float prisPerMeter, string profile, bool painted)
{
    if(this->counterVirke == this->virkeArrayCapacity)
    {
        virke **tmp = new virke *[this->virkeArrayCapacity];
        
        for(int i=0; i < this->counterVirke; i++)
	{
            tmp[i] = this->ptr2ArrayWithVirkePtr[i];
	}
        
        for(int i=0; i < this->counterVirke; i++)
	{
            delete this->ptr2ArrayWithVirkePtr[i];
	}
	delete [] this->ptr2ArrayWithVirkePtr;
    }
    this->ptr2ArrayWithVirkePtr[this->counterVirke+1]
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