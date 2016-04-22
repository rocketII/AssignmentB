//
// Created by root on 2016-04-12.
//

#ifndef ASSIGNMENTA_PROFESSIONELL_H
#define ASSIGNMENTA_PROFESSIONELL_H
#include"deltagare.h"
#include <string>
#include <sstream>
// used to be professionell...
using  namespace std;
class professionell : public  deltagare
{
private:
    string namn, kon, klubb;
    int nrOfActiveSeassons;

public:



    professionell(string namn, string kon, string klubb, int  nrOfActiveSeassons);
    professionell(const professionell& orgin);
    professionell& operator=(const professionell& orgin);

    virtual ~professionell() { }

    const string getKlubb() const ;

    void setKlubb(const string klubb);

    int getNrOfActiveSeassons() const; //

    void setNrOfActiveSeassons(int nrOfActiveSeassons);//

    virtual string toStringSpecific()const;
    virtual professionell* clone()const;
};


#endif //ASSIGNMENTA_PROFESSIONELL_H
