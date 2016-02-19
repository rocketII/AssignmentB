/*
 * Here I'm supposed to test virkemanager so that the class members copy construct,
 * destruct and operator= works.
 * 
 * No memory leaks allowed!!!!!!!!!
 * using valgrind
 */
#include <iostream>

#include"virkemanager.h"



void treVirkeManager()
{
	//declare, init
	Virkemanager myTimbers;
	myTimbers.newPanel("20x30",23.98,"basPanel", true);
	myTimbers.newRegel("450x234", 677.00, "K34");
	Virkemanager jacksTimbers;
	jacksTimbers.newPanel("20x300",23.98,"SubPanel", false);
	jacksTimbers.newRegel("40x24", 67.00, "K4");
	
	//print content
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	cout <<" I have the following objects stored: "<< myTimbers.AllDataVirke() << endl;
	
	
	//test = operator for class
	jacksTimbers = myTimbers;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	cout <<" I have the following objects stored: "<< myTimbers.AllDataVirke() << endl;
	
	//test copy constructor
	Virkemanager sarasTimbers= jacksTimbers;
	cout <<" Sara has the following objects stored: " << sarasTimbers.AllDataVirke() << endl;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	//try remove one obj from one and check if it change in other obj.
	sarasTimbers.removeVirke();
	cout <<" Sara has the following objects stored: " << sarasTimbers.AllDataVirke() << endl;
	cout <<" jack has the following objects stored: " << jacksTimbers.AllDataVirke() << endl;
	
	
	
	
}

