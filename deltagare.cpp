//
// Created by root on 2016-04-12.
//
#include "deltagare.h"

string deltagare::toString() const
{
    stringstream ff;
    ff << "\nNamn: "<<this->namn<<"\nKön: "<<this->kon<<this->toStringSpecific();
    return ff.str();
}

deltagare::deltagare(const deltagare &orgin)
{
    this->namn=orgin.namn;
    this->kon=orgin.kon;
}

deltagare &deltagare::operator=(const deltagare &orgin)
{
    if (this != &orgin)
    {
        this->namn=orgin.namn;
        this->kon=orgin.kon;
    }
    return *this;
}

const string deltagare::getNamn() const
{
    return namn;
}

void deltagare::setNamn(const string namn)
{
    deltagare::namn = namn;
}

const string deltagare::getKon() const
{
    return kon;
}

void deltagare::setKon(const string kon)
{
    deltagare::kon = kon;
}
