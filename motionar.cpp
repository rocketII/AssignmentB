//
// Created by root on 2016-04-12.
//

#include "motionar.h"
#include <sstream>


int motionar::getAlder() const
{
    return this->alder;
}

void motionar::setAlder(int alder)
{
    this->alder = alder;
}


string motionar::toStringSpecific() const
{
    stringstream ss;
    ss << "\nÅlder: " << this->alder;
    return ss.str();
}

motionar *motionar::clone() const
{
    return new motionar(*this);
}

motionar::motionar(const motionar &orgin) : deltagare(orgin)
{
    this->alder=orgin.alder;
}

motionar &motionar::operator=(const motionar &orgin)
{
    if (this != &orgin)
    {
        deltagare::operator=(orgin);
        this->alder=orgin.alder;
    }
    return *this;
}
