//
// Created by Roderik Bauhn on 2016-04-12.
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
    //data
    string namn;
public:
    Instrument();
    Instrument(const string &namn);
    Instrument& operator=(const Instrument& orgin);
    virtual ~Instrument();
    Instrument(const Instrument& orgin);
    //get and setters
    const string getNamn() const ;
    void setNamn(const string namn) ;
    //data to string
    virtual string toStringSpecific(void)const =0; // inherited and a must define function.
    string toString()const;
    //used in Register Class in order to move data to another Register **array.
    virtual Instrument* clone() const=0;


};


#endif //ASSIGNMENTB_Instrument_H
