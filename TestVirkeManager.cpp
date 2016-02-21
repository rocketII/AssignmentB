/*
 * Here I'm supposed to test virkemanager so that the class members copy construct,
 * destruct and operator= works.
 * 
 * No memory leaks allowed!!!!!!!!!
 * using valgrind
 */
#include <iostream>

#include"virkemanager.h"



bool testSuitVirkeManager()
{
	bool flag=false;
	//declare, init
	Virkemanager myTimbers;
	cout << "created virkemanager myTimbers and next I'm gonna init two obj ptrs in array one Panel(20x30\",23.98,\" basPanel\", true) and one Regel(\"450x234\", 677.00, \"K34\")" << endl;
	myTimbers.newPanel("20x30",23.98,"basPanel", true);
	myTimbers.newRegel("450x234", 677.00, "K34");
	cout<<"myTimbers have "<<myTimbers.getcounterVirke() <<" obj ptrs and the array can hold a total of " <<myTimbers.getvirkeArrayCapacity()<<" units"<<endl;
	cout << "creating jacksTimber" <<endl;
	Virkemanager jacksTimbers;
	cout << "next I'm gonna init two obj ptrs in array one Panel(\"20x300\",23.98,\"SubPanel\", false) and one Regel(\"40x24\", 67.00, \"K4\")" << endl;
	jacksTimbers.newPanel("20x300",23.98,"SubPanel", false);
	jacksTimbers.newRegel("40x24", 67.00, "K4");
	cout<<"jacksTimbers have "<< jacksTimbers.getcounterVirke() <<" obj ptrs and the array can hold a total of " <<jacksTimbers.getvirkeArrayCapacity()<<" units"<<endl;
	
	
	//print content
	string *results;
	cout <<" jack has the following objects stored: "<< endl;
	results=&(jacksTimbers.AllDataVirke());
	for(int i =0; i < 2 ; i++) //replace jacksTimbers.getcounterVirke()
	{
		cout << i <<": "<< results[i]<<endl;
	}
	cout <<" I have the following objects stored: "<< myTimbers.AllDataVirke() << endl;
	results=&(myTimbers.AllDataVirke());
	for(int i =0; i < 2; i++)//replace 2 with myTimbers.getcounterVirke()
	{
		cout << i <<": "<< results[i]<<endl;
	}//*/
	/*
	//test = operator for class
	cout << "Now I'm going to try the = operator" << endl;
	jacksTimbers = myTimbers;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	cout <<" I have the following objects stored: "<< myTimbers.AllDataVirke() << endl;
	
	//test copy constructor
	cout << "Now I'm going to try the copy consructor" << endl;
	Virkemanager sarasTimbers= jacksTimbers;
	cout<<"sarasTimbers have "<< sarasTimbers.getcounterVirke() <<" obj ptrs and the array can hold a total of " <<sarasTimbers.getvirkeArrayCapacity()<<" units"<<endl;
	cout<<"jacksTimbers have "<< jacksTimbers.getcounterVirke() <<" obj ptrs and the array can hold a total of " <<jacksTimbers.getvirkeArrayCapacity()<<" units"<<endl;
	cout <<" Sara has the following objects stored: " << sarasTimbers.AllDataVirke() << endl;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	//try remove one obj from one and check if it change in other obj.
	cout << "Now I'm going to try deep copying diagnostic. I remove one of saras objs and if it works it won't affect the other obj of jack that recived from the removed obj" << endl;
	sarasTimbers.removeVirke(23.98, "20x30");
	cout<<"sarasTimbers have "<< sarasTimbers.getcounterVirke() <<" obj ptrs and the array can hold a total of " <<sarasTimbers.getvirkeArrayCapacity()<<" units"<<endl;
	cout <<" Sara has the following objects stored: " << sarasTimbers.AllDataVirke() << endl;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	*/
	flag = true;
	return flag;
	
	
}

