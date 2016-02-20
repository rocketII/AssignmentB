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
    this->counterVirke=0;
    this->virkeArrayCapacity=2;
    this->virkeDataTmpCache="currently empty";
    this->ptr2ArrayWithVirkePtr= new virke*[this->virkeArrayCapacity];
}
	
	//destruct
Virkemanager::~Virkemanager()
{
	//maybe we should add some more controls so we don't try to free memory we don't own?
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
	bool flag = false;
	if(this->counterVirke < this->virkeArrayCapacity)
	{
		this->ptr2ArrayWithVirkePtr[this->counterVirke+1]= new paneler( dimension, prisPerMeter, profile, painted);
		flag=true;
		this->counterVirke++;
	}
	else
	{
		this->virkeArrayCapacity += 3;
		//creating tmp **ptr to array of ptr objs
		virke **tmp = new virke *[this->virkeArrayCapacity];
			//filling tmp with ptrs to objs
		for(int i=0; i < this->counterVirke; i++)
		{
			tmp[i] = this->ptr2ArrayWithVirkePtr[i];
		}
		//delete this ptr2ArrayWith...Ptr
		for(int i=0; i < this->counterVirke; i++)
		{
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		delete [] this->ptr2ArrayWithVirkePtr;
		//create bigger ptr2Array..,Ptr
		this->ptr2ArrayWithVirkePtr = new paneler *[this->virkeArrayCapacity];
		//filling this with tmp data
		for(int i=0; i < this->counterVirke; i++)
		{
			this->ptr2ArrayWithVirkePtr[i] = tmp[i];
		}
		//redirect tmp to null or nullptr or nullptr_t
		tmp=NULL;
		//now add new obj
		this->ptr2ArrayWithVirkePtr[this->counterVirke+1]= new paneler( dimension, prisPerMeter, profile, painted);
		flag=true;
		this->counterVirke++;
	}
	return flag;
}
bool Virkemanager::newRegel(string dimension, float prisPerMeter, string klassificering)
{
	bool flag = false;
	if(this->counterVirke < this->virkeArrayCapacity)
	{
		this->ptr2ArrayWithVirkePtr[this->counterVirke+1]= new reglar( dimension,prisPerMeter, klassificering);
		flag=true;
		this->counterVirke++;
	}
	else
	{
		this->virkeArrayCapacity += 3;
			//creating tmp **ptr to array of ptr objs
		virke **tmp = new virke *[this->virkeArrayCapacity];
			//filling tmp with ptrs to objs
		for(int i=0; i < this->counterVirke; i++)
		{
		    tmp[i] = this->ptr2ArrayWithVirkePtr[i];
		}
			//delete this ptr2ArrayWith...Ptr
		for(int i=0; i < this->counterVirke; i++)
		{
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		delete [] this->ptr2ArrayWithVirkePtr;
			//create bigger ptr2Array..,Ptr
		this->ptr2ArrayWithVirkePtr = new reglar *[this->virkeArrayCapacity];
			//filling this with tmp data
		for(int i=0; i < this->counterVirke; i++)
		{
			this->ptr2ArrayWithVirkePtr[i] = tmp[i];
		}
			//redirect tmp to null or nullptr or nullptr_t
		tmp=NULL;
			//now add new obj
		this->ptr2ArrayWithVirkePtr[this->counterVirke+1]= new reglar( dimension, prisPerMeter, klassificering);
		flag=true;
		this->counterVirke++;
	}
	return flag;
}
bool Virkemanager::changePaintedStatus(string dimension, string profile)
{
	bool flag=false;
	//go through the array and check for paneler type and then look for matching dimenson and profile
	//if match found then change bool to oposite
	for(int i = 0; i < this->counterVirke; i++)
	{
		if(typeid(*this->ptr2ArrayWithVirkePtr[i]) == typeid(paneler))
		{
			if(this->ptr2ArrayWithVirkePtr[i]-> == dimension && this->ptr2ArrayWithVirkePtr[i]-> == profile)
			{
				//abusing dynamic_cast in order to access paneler member functions.
				dynamic_cast<paneler*>(this->ptr2ArrayWithVirkePtr[i])->setPainted(!(dynamic_cast<paneler*>(this->ptr2ArrayWithVirkePtr[i])->getPainted()));
				flag = true;
			}
		}
	}
	return flag;
            
}
		//Walkthrough the array with obj ptrs and get all the data as string
string& Virkemanager::AllDataVirke()
{
	//stringstream ss, kk, ll;
	string tmpCache= new string[this->counterVirke];
	for(int i; i < this->counterVirke; i++)
	{
		tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() << "\n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << "\n";
	}
	return &tmpCache;
}
	//Walkthrough the array with obj ptrs and get all the data as string. But now we only take Ramar. 
string& Virkemanager::AllDataReglar()
{
	string tmpCache= new string[this->numberOfReglar()];
	for(int i; i < this->counterVirke; i++)
	{
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])== typeid(reglar))
		{
			for(int i; i < this->counterVirke; i++)
			{
				tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() << "\n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << "\n";
			}
		}
	}
	return &tmpCache;
}
string& Virkemanager::AllDataPaneler()
{
	string tmpCache= new string[this->numberOfPaneler()];
	for(int i; i < this->counterVirke; i++)
	{
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])== typeid(paneler))
		{
			for(int i; i < this->counterVirke; i++)
			{
				tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() << "\n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << "\n";
			}
		}
	}
	return &tmpCache;
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