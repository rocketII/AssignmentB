//
// Created by root on 2016-04-12.
//used to be motionar.

#ifndef ASSIGNMENTA_MOTIONAR_H
#define ASSIGNMENTA_MOTIONAR_H

#include "deltagare.h"
#include <string>
using namespace std;
class motionar : public  deltagare
{
private:
    string namn, kon;
    int alder;
public:


    motionar(const string namn, const string kon, int alder) : deltagare(namn, kon), alder(alder) { }
    motionar(const motionar& orgin);
    motionar& operator=(const motionar& orgin);

    virtual ~motionar() { }

    int getAlder() const;

    void setAlder(int alder);

    virtual string toStringSpecific() const;
    virtual motionar* clone()const;

};


#endif //ASSIGNMENTA_MOTIONAR_H
