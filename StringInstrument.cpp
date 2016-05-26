//
// Created by Roderik Bauhn on 2016-04-12.
//

#include "StringInstrument.h"
#include <sstream>
bool StringInstrument::getStrakInstrument() const
{
    return this->strakInstrument;
}

void StringInstrument::setStrakInstrument(bool strakInstrument)
{
    this->strakInstrument = strakInstrument;
}

bool StringInstrument::getKnappInstrument() const
{
    return this->knappInstrument;
}

void StringInstrument::setKnappInstrument(bool knappInstrument)
{
    this->knappInstrument = knappInstrument;
}

int StringInstrument::getNrOfStrings() const
{
    return this->nrOfStrings;
}

void StringInstrument::setNrOfStrings(int nrOfStrings)
{
    this->nrOfStrings = nrOfStrings;
}

string StringInstrument::toStringSpecific() const
{
    stringstream ss;
    string knapp, strake;
    if(this->getKnappInstrument() == true)
    {
        knapp = "falskt";
        strake = "sant";
    }
    else
    {
        knapp = "sant";
        strake = "falskt";
    }
    ss << "\nAntal Strängar: " << this->nrOfStrings<<"\nKnäppinstrument: "<< knapp<<"\nStråkinstrument: " <<strake;
    return ss.str();
}

StringInstrument *StringInstrument::clone() const
{
    return new StringInstrument(*this);
}

StringInstrument::StringInstrument(const StringInstrument &orgin) : Instrument(orgin)
{
    this->nrOfStrings = orgin.nrOfStrings;
    this->knappInstrument = orgin.knappInstrument;
    this->strakInstrument = orgin.strakInstrument;
}

StringInstrument &StringInstrument::operator=(const StringInstrument &orgin)
{
    if (this != &orgin)
    {
        Instrument::operator=(orgin);
        this->nrOfStrings =orgin.nrOfStrings;
        this->knappInstrument = orgin.knappInstrument;
        this->strakInstrument = orgin.strakInstrument;
    }
    return *this;
}

StringInstrument::StringInstrument(const string namn, int nrOfStrings, bool strakInstrument, bool knappInstrument) : Instrument(namn), nrOfStrings(nrOfStrings), strakInstrument(strakInstrument), knappInstrument(knappInstrument)
{

}

StringInstrument::~StringInstrument()
{

}
