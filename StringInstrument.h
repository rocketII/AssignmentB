//
// Created by Roderik Bauhn on 2016-04-12.


#ifndef ASSIGNMENTA_MOTIONAR_H
#define ASSIGNMENTA_MOTIONAR_H

#include "Instrument.h"
#include <string>
using namespace std;
class StringInstrument : public  Instrument
{
private:
    //stråk- eller knäpp-instrument
    //data
    bool strakInstrument;
    bool knappInstrument;
    int  nrOfStrings;
public:
    //functions manage get and set. prints data to string through stringstream techniques.
    bool getStrakInstrument() const;

    void setStrakInstrument(bool strakInstrument);

    bool getKnappInstrument() const;

    void setKnappInstrument(bool knappInstrument);

    int getNrOfStrings() const ;
    void setNrOfStrings(int nrOfStrings) ;

    StringInstrument(const string namn, int nrOfStrings, bool strakInstrument, bool knappInstrument);
    StringInstrument(const StringInstrument & orgin);
    StringInstrument& operator=(const StringInstrument & orgin);

    virtual ~StringInstrument();
    virtual string toStringSpecific() const;
    //used in Register Class in order to move data to another Register **array.
    virtual StringInstrument * clone()const;

};


#endif //ASSIGNMENTA_MOTIONAR_H
