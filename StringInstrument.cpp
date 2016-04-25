//
// Created by root on 2016-04-12.
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
    ss << "\nAntal Strängar: " << this->nrOfStrings<<"\nKnäppinstrument: "<< this->getKnappInstrument()<<"\nStråkinstrument: " <<this->getStrakInstrument();
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
