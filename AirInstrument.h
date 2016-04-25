//
// Created by root on 2016-04-12.
//

#ifndef ASSIGNMENTA_PROFESSIONELL_H
#define ASSIGNMENTA_PROFESSIONELL_H
#include "Instrument.h"
#include <string>
#include <sstream>
// used to be professionell...
using  namespace std;
class AirInstrument : public  Instrument
{
private:
    //träblås- eller bleckblås
    bool trablas, bleckblas;


public:



    AirInstrument(string namn, bool trablas, bool bleckblas);
    AirInstrument(const AirInstrument & orgin);
    AirInstrument & operator=(const AirInstrument & orgin);

    virtual ~AirInstrument() { }

    virtual string toStringSpecific()const;
    virtual AirInstrument * clone()const;

    bool getTrablas() const ;

    void setTrablas(bool trablas) ;

    bool getBleckblas() const ;

    void setBleckblas(bool bleckblas);

};


#endif //ASSIGNMENTA_PROFESSIONELL_H
