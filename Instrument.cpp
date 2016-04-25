//
// Created by Roderik Bauhn on 2016-04-12.
//
#include "Instrument.h"

string Instrument::toString() const
{
    stringstream ff;
    ff << "\nNamn: "<<this->namn<<this->toStringSpecific();
    return ff.str();
}

Instrument::Instrument(const Instrument &orgin)
{
    this->namn=orgin.namn;

}

Instrument& Instrument::operator=(const Instrument &orgin)
{
    if (this != &orgin)
    {
        this->namn=orgin.namn;

    }
    return *this;
}

const string Instrument::getNamn() const
{
    return namn;
}

void Instrument::setNamn(const string namn)
{
    Instrument::namn = namn;
}

