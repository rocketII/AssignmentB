//
// Created by root on 2016-04-12.
//

#ifndef Instrument_H
#define Instrument_H
#include <string>
#include <sstream>
//Ska vara abstrakt
using  namespace std;
class Instrument
{
private:
    string namn;
public:
    Instrument(){};
    Instrument(const string &namn) : namn(namn){ }
    Instrument& operator=(const Instrument& orgin);
    virtual ~Instrument() { }
    Instrument(const Instrument& orgin);
    const string getNamn() const ;
    void setNamn(const string namn) ;
    virtual string toStringSpecific(void)const =0;
    virtual Instrument* clone() const=0;
    string toString()const;

};


#endif //ASSIGNMENTB_Instrument_H
