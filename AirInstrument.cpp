//
// Created by root on 2016-04-12.
//

#include "AirInstrument.h"

const string professionell::getKlubb() const
{
    return this->klubb;
}

void professionell::setKlubb(const string klubb)
{
    this->klubb = klubb;
}

int professionell::getNrOfActiveSeassons() const
{
    return this->nrOfActiveSeassons;
}

void professionell::setNrOfActiveSeassons(int nrOfActiveSeassons)
{
    this->nrOfActiveSeassons = nrOfActiveSeassons;
}

professionell::professionell(string namn, string kon, string klubb, int  nrOfActiveSeassons) : deltagare(namn, kon), klubb(klubb), nrOfActiveSeassons(nrOfActiveSeassons)
{

}

string professionell::toStringSpecific() const
{
    stringstream rr;
    rr << "\nklubb: " << this->klubb << "\nAntal aktiva sässonger: " << this->nrOfActiveSeassons;
    return rr.str();
}

professionell *professionell::clone() const {
    return new professionell(*this);
}

professionell::professionell(const professionell &orgin) : deltagare(orgin)
{
    this->klubb=orgin.klubb;
    this->nrOfActiveSeassons=orgin.nrOfActiveSeassons;
}

professionell &professionell::operator=(const professionell &orgin)
{
    if(this != &orgin)
    {
        deltagare::operator=(orgin);
        this->nrOfActiveSeassons = orgin.nrOfActiveSeassons;
        this->klubb = orgin.klubb;
    }
    return *this;
}
