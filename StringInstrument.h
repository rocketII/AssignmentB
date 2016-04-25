//
// Created by Roderik Bauhn on 2016-04-12.
//used to be motionar.

#ifndef ASSIGNMENTA_MOTIONAR_H
#define ASSIGNMENTA_MOTIONAR_H

#include "Instrument.h"
#include <string>
using namespace std;
class StringInstrument : public  Instrument
{
private:
    //stråk- eller knäpp-instrument
    bool strakInstrument;
    bool knappInstrument;
    int nrOfStrings;
public:

    bool getStrakInstrument() const;

    void setStrakInstrument(bool strakInstrument);

    bool getKnappInstrument() const;

    void setKnappInstrument(bool knappInstrument);

    int getNrOfStrings() const ;
    void setNrOfStrings(int nrOfStrings) ;

    StringInstrument(const string namn, int nrOfStrings, bool strakInstrument, bool knappInstrument) : Instrument(namn), nrOfStrings(nrOfStrings), strakInstrument(strakInstrument), knappInstrument(knappInstrument)
    {    }
    StringInstrument(const StringInstrument & orgin);
    StringInstrument& operator=(const StringInstrument & orgin);

    virtual ~StringInstrument() { }



    virtual string toStringSpecific() const;
    virtual StringInstrument * clone()const;

};


#endif //ASSIGNMENTA_MOTIONAR_H
