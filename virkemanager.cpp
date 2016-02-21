/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<typeinfo>
//iostream == debug
//#include<iostream>
#include "virkemanager.h"
using namespace std;

//construct
Virkemanager::Virkemanager()
{
	//cout<<"Virkemanager constructor."<<endl;
	this->counterVirke=0;
	this->virkeArrayCapacity=2;
	//this->virkeDataTmpCache="currently empty";
	this->ptr2ArrayWithVirkePtr= new virke*[this->virkeArrayCapacity];
	this->stringArrayGotInit= false;
	//cout<<"Virkemanager constructor.Done. "<<" countervirke"<<this->counterVirke<<" stringArrayGotInit"<<this->stringArrayGotInit<<" virkeArrayCapacity"<<this->virkeArrayCapacity<<endl;
}
	
	//destruct
Virkemanager::~Virkemanager()
{
	//cout<<"Virkemanager destruct."<<endl;
	//maybe we should add some more controls so we don't try to free memory we don't own?
	for(int i=0; i< this->counterVirke; i++)
	{
		//cout<<"Virkemanager destruct. Deleting objPtr in array..."<<endl;
		delete this->ptr2ArrayWithVirkePtr[i];
	}
	//cout<<"Virkemanager destructor. Deleting Array"<<endl;
	delete [] this->ptr2ArrayWithVirkePtr;
	if(this->stringArrayGotInit)
	{
		//cout<<"Virkemanager destruct. passed if stringArrayGotInit. Deleting string array"<<endl;
		delete [] this->tmpCache;    
	}
	//cout<<"Virkemanager destruct. I'm Done here."<<endl;
    
}
	
	//construct with same class obj, aka copy construct
Virkemanager::Virkemanager(const Virkemanager &origin)
{
	//cout<<"Virkemanager copy construct."<<endl;
	this->stringArrayGotInit=false;
	this->counterVirke= origin.counterVirke;
	this->virkeArrayCapacity=origin.virkeArrayCapacity; // hur stor array man behöver för memalloc
	//cout<<"Virkemanager copy construct. Done assigning this counterVirke "<<this->counterVirke<<" and virkeArray "<< this->virkeArrayCapacity<<"."<<endl;
	//cout<<"Virkemanager copy construct. creating array for **ptr."<<endl;
	this->ptr2ArrayWithVirkePtr= new virke *[this->virkeArrayCapacity];
	for(int i=0; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager cpy constr. checking typeid for array element type."<<endl;
                //check the origin element wise and look at each obj type paneler or reglar and alloc space for the obj type.
		if(typeid(*origin.ptr2ArrayWithVirkePtr[i])==typeid(paneler))
		{
			//cout<<"Virkemanager cpy constr. typeid paneler. So creating new panel obj."<<endl;
			this->ptr2ArrayWithVirkePtr[i]= new paneler(*((paneler*)origin.ptr2ArrayWithVirkePtr[i])); 
		}
		else
		{
			//cout<<"Virkemanager cpy constr. typeid reglar. So creating new reglar obj."<<endl;
			this->ptr2ArrayWithVirkePtr[i]= new reglar(*((reglar*)origin.ptr2ArrayWithVirkePtr[i])); 
		}
	}
	//cout<<"Virkemanager cpy constr.I'm Done"<<endl;
}
	
	//overiding the '=' operator
Virkemanager& Virkemanager::operator=(const Virkemanager &origin)
{
	//cout<<"Virkemanager = op."<<endl;
	if(this != &origin)
	{
		//cout<<"Virkemanager = op. if test passed. this!=origin."<<endl;
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager = op.Deleting element ptr..."<<endl;
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		//cout<<"Virkemanager = op.Deleting array..."<<endl;
		delete [] this->ptr2ArrayWithVirkePtr;
		
		this->counterVirke=origin.counterVirke;
		this->virkeArrayCapacity=origin.virkeArrayCapacity;
		//cout<<"Virkemanager = op.I'm Done assigning two from origin"<<". counterVirke= "<<origin.counterVirke<<" virkeArrayCap= "<<origin.virkeArrayCapacity<<endl;
		//cout<<"Virkemanager = op.I'm Done assigning two into this"<<". counterVirke= "<<this->counterVirke<<" virkeArrayCap= "<<this->virkeArrayCapacity<<endl;
		//cout<<"Virkemanager = op.creating array."<<endl;
		this->ptr2ArrayWithVirkePtr= new virke *[this->virkeArrayCapacity];
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager = op.for-looping, checking typeId in origin."<<endl;
			if(typeid(*origin.ptr2ArrayWithVirkePtr[i])==typeid(reglar))
			{
				//cout<<"Virkemanager = op. typeid in origin reglar. creating new obj."<<endl;
				this->ptr2ArrayWithVirkePtr[i]=new reglar(*((reglar*)origin.ptr2ArrayWithVirkePtr[i]));
			}
			else
			{
				//cout<<"Virkemanager = op.typeid in origin paneler. creating new obj."<<endl;
				this->ptr2ArrayWithVirkePtr[i]=new paneler(*((paneler*)origin.ptr2ArrayWithVirkePtr[i]));
			}
			 
		}
	}
	//cout<<"Virkemanager = op.I'm done here."<<endl;
	return *this;
}
bool Virkemanager::newPanel(string dimension, float prisPerMeter, string profile, bool painted)
{
	//cout<<"Virkemanager newpanel()"<<endl;
	bool flag = false;
	if(this->counterVirke < this->virkeArrayCapacity)
	{
		//cout<<"Virkemanager newpanel(). stille room for more."<<endl;
		//cout<<"Virkemanager newpanel(). adding new panel obj in next empty."<<endl;
		this->ptr2ArrayWithVirkePtr[this->counterVirke]= new paneler( prisPerMeter, dimension, profile, painted);
		flag=true;
		this->counterVirke++;
	}
	else
	{
		//cout<<"Virkemanager newpanel(). No room left."<<endl;
		this->virkeArrayCapacity += 3;
		//creating tmp **ptr to array of ptr objs
		virke **tmp = new virke *[this->virkeArrayCapacity];
			//filling tmp with ptrs to objs
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newpanel(). coping ptr"<<endl;
			tmp[i] = this->ptr2ArrayWithVirkePtr[i];
		}
		//delete this ptr2ArrayWith...Ptr
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newpanel(). Deletin obj ptr..."<<endl;
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		//cout<<"Virkemanager newpanel(). Deleting array."<<endl;
		delete [] this->ptr2ArrayWithVirkePtr;
		//create bigger ptr2Array..,Ptr
		//cout<<"Virkemanager newpanel(). creating bigger array."<<endl;
		this->ptr2ArrayWithVirkePtr = new virke *[this->virkeArrayCapacity];
		//filling this with tmp data
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newpanel(). cpy obj ptr"<<endl;
			this->ptr2ArrayWithVirkePtr[i] = tmp[i];
		}
		//redirect tmp to null or nullptr or nullptr_t
		//cout<<"Virkemanager newpanel(). tmp **ptr assign null"<<endl;
		tmp=NULL;
		//now add new obj
		//cout<<"Virkemanager newpanel(). creating new obj."<<endl;
		this->ptr2ArrayWithVirkePtr[this->counterVirke++]= new paneler( prisPerMeter, dimension, profile, painted);
		flag=true;
		
	}
	//cout<<"Virkemanager newpanel(). done."<<endl;
	return flag;
}
bool Virkemanager::newRegel(string dimension, float prisPerMeter, string klassificering)
{
	//cout<<"Virkemanager newregel()"<<endl;
	bool flag = false;
	if(this->counterVirke < this->virkeArrayCapacity)
	{
		//cout<<"Virkemanager newregel(). There's room. creating obj"<<endl;
		this->ptr2ArrayWithVirkePtr[this->counterVirke]= new reglar( prisPerMeter, dimension, klassificering);
		flag=true;
		this->counterVirke++;
	}
	else
	{
		//cout<<"Virkemanager newregel(). No space.. going to fix that."<<endl;
		this->virkeArrayCapacity += 3;
			//creating tmp **ptr to array of ptr objs
		virke **tmp = new virke *[this->virkeArrayCapacity];
			//filling tmp with ptrs to objs
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newregel(). copying 2 tmp"<<endl;
			tmp[i] = this->ptr2ArrayWithVirkePtr[i];
		}
			//delete this ptr2ArrayWith...Ptr
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newregel(). deleting ptr obj..."<<endl;
			delete this->ptr2ArrayWithVirkePtr[i];
		}
		//cout<<"Virkemanager newregel(). Deleting array."<<endl;
		delete [] this->ptr2ArrayWithVirkePtr;
			//create bigger ptr2Array..,Ptr
		//cout<<"Virkemanager newregel(). new bigger array"<<endl;
		this->ptr2ArrayWithVirkePtr = new virke *[this->virkeArrayCapacity];
			//filling this with tmp data
		for(int i=0; i < this->counterVirke; i++)
		{
			//cout<<"Virkemanager newregel(). copy from tmp to this **ptr"<<endl;
			this->ptr2ArrayWithVirkePtr[i] = tmp[i];
		}
			//redirect tmp to null or nullptr or nullptr_t
		//cout<<"Virkemanager newregel(). tmp got NULL"<<endl;
		tmp=NULL;
			//now add new obj
		//cout<<"Virkemanager newregel(). Adding new obj ptr."<<endl;
		this->ptr2ArrayWithVirkePtr[this->counterVirke]= new reglar(prisPerMeter, dimension, klassificering);
		flag=true;
		this->counterVirke++;
	}
	//cout<<"Virkemanager newregel(). It's done."<<endl;
	return flag;
}
bool Virkemanager::changePaintedStatus(string dimension, string profile)
{
	//cout<<"Virkemanager changePaintedStatus()"<<endl;
	bool flag=false;
	//go through the array and check for paneler type and then look for matching dimenson and profile
	//if match found then change bool to oposite
	for(int i = 0; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager changePaintedStatus(). for-looping. checking typeid."<<endl;
		if(typeid(*this->ptr2ArrayWithVirkePtr[i]) == typeid(paneler))
		{
			//cout<<"Virkemanager changePaintedStatus(). typeID paneler."<<endl;
			if(this->ptr2ArrayWithVirkePtr[i]->getDimension() == dimension && (dynamic_cast<paneler*>(this->ptr2ArrayWithVirkePtr[i]))->getProfile() == profile)
			{
				
				//cout<<"Virkemanager changePaintedStatus()."<<endl;
				//abusing dynamic_cast in order to access paneler member functions.
				dynamic_cast<paneler*>(this->ptr2ArrayWithVirkePtr[i])->setPainted(!(dynamic_cast<paneler*>(this->ptr2ArrayWithVirkePtr[i])->getPainted()));
				flag = true;
			}
			
		}
	}
	//debug remove later
	/*if(!flag)
	{
		cout<<"none found! try something else"<<endl;
	}
	else
	{
		cout<<"found match, changed value"<<endl;
	}
	cout<<"Virkemanager changePaintedStatus(). Done here."<<endl; */
	return flag;
            
}
		//Walkthrough the array with obj ptrs and get all the data as string
string& Virkemanager::AllDataVirke()const
{
	//cout<<"Virkemanager AllDataVirke()"<<endl;
	//stringstream ss, kk, ll;
	//cout<<"Virkemanager AllDataVirke(). creating new string array if not alredy done. ini 0 and 1"<<endl;
	if(!this->stringArrayGotInit)
	{
		//cout <<"virkemanager: array not alloc before.";
		string *tmpCache= new string[this->getcounterVirke()];
		this->stringArrayGotInit=true;
	}
	else
	{
		//cout<<"exist! deleting. creating space for each virke obj data string"<<endl;
		delete [] this->tmpCache;
		string *tmpCache = new string[this->getcounterVirke()];
		this->stringArrayGotInit=true;
	}
	//debug purpose, remove this later
	//this->tmpCache[0]="default"; this->tmpCache[1]=" value";
	//end
	this->stringArrayGotInit=true;
	for(int i; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager AllDataVirke(). couting data."<< endl;
		//cout for debug only remove or comment out
		tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() <<" \n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << std::endl;
	}
	//cout<<"Virkemanager AllDataVirke(). Finished."<<endl;
	return *tmpCache;
}
	//Walkthrough the array with obj ptrs and get all the data as string. But now we only take Ramar. 
string& Virkemanager::AllDataReglar()const
{
	//cout<<"Virkemanager AllDataReglar()"<<endl;
	
	if(!this->stringArrayGotInit)
	{
		//cout <<"virkemanager: array not alloc before.";
		string *tmpCache= new string[this->getNumberOfReglar()];
		this->stringArrayGotInit=true;
	}
	else
	{
		//cout<<"exist! deleting. creating space for each regel obj string of data"<<endl;
		delete [] this->tmpCache;
		string *tmpCache= new string[this->getNumberOfReglar()];
		this->stringArrayGotInit=true;
	}
	
	//debug remove this
	this->tmpCache[0]="default"; this->tmpCache[1]=" value";
	//end
	
	for(int i; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager AllDataReglar(). checking typeID"<<endl;
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])== typeid(reglar))
		{
			//cout<<"Virkemanager AllDataReglar(). typeID are reglar."<<endl;
			//cout<<"Virkemanager AllDataReglar(). Couting."<<endl;
			//cout for debug only remove or comment out
			tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() << " \n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << std::endl;
			
		}
	}
	//cout<<"Virkemanager AllDataReglar(). Done."<<endl;
	return *tmpCache;
}
string& Virkemanager::AllDataPaneler()const
{
	//cout<<"Virkemanager AllDataPaneler()"<<endl;
	if(!this->stringArrayGotInit)
	{
		//cout <<"virkemanager: array not alloc before.";
		string *tmpCache= new string[this->getNumberOfPaneler()];
		this->stringArrayGotInit=true;
	}
	else
	{
		//cout<<"exist! deleting. creating space for each panel obj data string"<<endl;
		delete [] this->tmpCache;
		string *tmpCache= new string[this->getNumberOfPaneler()];
		this->stringArrayGotInit=true;
	}
	//debug remove this
	this->tmpCache[0]="default"; this->tmpCache[1]=" value";
	//end
	
	for(int i; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager AllDataPaneler(). Looping. checking id"<<endl;
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])== typeid(paneler))
		{
			//cout<<"Virkemanager AllDataPaneler().typeId==paneler. "<<endl;			
			//cout<<"Virkemanager AllDataPaneler()"<<endl;
			//cout for debug only remove or comment out
			tmpCache[i] << this->ptr2ArrayWithVirkePtr[i]->tostring() << " \n" << this->ptr2ArrayWithVirkePtr[i]->toStringSpec() << std::endl;
			
		}
	}
	//cout<<"Virkemanager AllDataPaneler(). Finished"<<endl;
	return *tmpCache;
}        
bool Virkemanager::removeVirke(float price, string dimension)
{
	bool flag = false;
	//cout<<"Virkemanager removeVirke()"<<endl;
	for(int i=0; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager removeVirke(). for-looping"<<endl;
		if( this->ptr2ArrayWithVirkePtr[i]->getDimension() == dimension && this->ptr2ArrayWithVirkePtr[i]->getPrisPerMeter() == price)
		{
			//cout<<"Virkemanager removeVirke(). if statement true. deleting obj ptr."<<endl;
			delete this->ptr2ArrayWithVirkePtr[i];
			flag = true;
				//asigning the empty slot with the last pointer
			//cout<<"Virkemanager removeVirke(). Last place fills deleted and last place gets delete"<<endl;
			this->ptr2ArrayWithVirkePtr[i] == this->ptr2ArrayWithVirkePtr[this->counterVirke - 1];
				//we got one duplicate so I remove the last that I prevoisly copied
			delete this->ptr2ArrayWithVirkePtr[this->counterVirke-1];
		}
	}
	//cout<<"Virkemanager removeVirke(). It's done"<<endl;
	return flag;
}
	
	//numberOf used with changing string array holder of virke data.
int Virkemanager::getNumberOfReglar()const
{
	//cout<<"Virkemanager numberOfReglar()"<<endl;
	int numberOfReglar=0;
	for(int i=0; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager numberOfReglar(). for-looping checking id."<<endl;
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])==typeid(reglar))
		{
			//cout<<"Virkemanager numberOfReglar(). ID == reglar. counter ++"<<endl;
			numberOfReglar++;
		}
	}
	//cout<<"Virkemanager numberOfReglar(). It's done."<<endl;
	return numberOfReglar;
}
int Virkemanager::getNumberOfPaneler()const
{
	//cout<<"Virkemanager numberOfPaneler()"<<endl;
	int numberOfPaneler=0;
	for(int i=0; i < this->counterVirke; i++)
	{
		//cout<<"Virkemanager numberOfPaneler(). for-looping checking id..."<<endl;
		if(typeid(*this->ptr2ArrayWithVirkePtr[i])==typeid(paneler))
		{
			//cout<<"Virkemanager numberOfPaneler(). id== paneler. counter++"<<endl;
			numberOfPaneler++;
		}
	}
	//cout<<"Virkemanager numberOfPaneler(). nothing more to see here. move along."<<endl;
	return numberOfPaneler;
}
int Virkemanager::getcounterVirke()const
{
	return this->counterVirke; 
}
int Virkemanager::getvirkeArrayCapacity()const
{
	return this->virkeArrayCapacity;
}
////////////////////////////////////////////////////////////////////////////////