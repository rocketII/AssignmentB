//
// Created by Roderik Bauhn on 2016-04-12.
//

#include "AirInstrument.h"

bool AirInstrument::getTrablas() const
{
    return this->trablas;
}

void AirInstrument::setTrablas(bool trablas) {
    this->trablas = trablas;
}

bool AirInstrument::getBleckblas() const
{
    return this->bleckblas;
}

void AirInstrument::setBleckblas(bool bleckblas)
{
    this->bleckblas = bleckblas;
}


AirInstrument::AirInstrument(string namn,  bool trablas,bool bleckblas) : Instrument(namn), bleckblas(bleckblas), trablas(trablas)
{

}

string AirInstrument::toStringSpecific() const
{
    stringstream rr;
    string Bleckblas, trablas;
    if(this->getBleckblas() == true)
    {
        Bleckblas = "falskt";
        trablas = "sant";
    }
    else
    {
        Bleckblas = "sant";
        trablas = "falskt";
    }
    rr << "\nBleckblås: " << Bleckblas << "\n:Träblås: " << trablas;
    return rr.str();
}

AirInstrument *AirInstrument::clone() const {
    return new AirInstrument(*this);
}

AirInstrument::AirInstrument(const AirInstrument &orgin) : Instrument(orgin)
{
    this->bleckblas = orgin.bleckblas;
    this->trablas = orgin.trablas;
}

AirInstrument &AirInstrument::operator=(const AirInstrument &orgin)
{
    if(this != &orgin)
    {
        Instrument::operator=(orgin);
        this->bleckblas = orgin.bleckblas;
        this->trablas = orgin.trablas;
    }
    return *this;
}
