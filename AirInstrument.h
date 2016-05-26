//
// Created by Roderik Bauhn on 2016-04-12.
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
    //data
    bool trablas, bleckblas;


public:


    //functions manage get and set. prints data to string through stringstream techniques.
    AirInstrument(string namn, bool trablas, bool bleckblas);
    AirInstrument(const AirInstrument & orgin);
    AirInstrument & operator=(const AirInstrument & orgin);

    virtual ~AirInstrument();

    virtual string toStringSpecific()const;


    bool getTrablas() const ;

    void setTrablas(bool trablas) ;

    bool getBleckblas() const ;

    void setBleckblas(bool bleckblas);
    //used in Register Class in order to move data to another Register **array.
    virtual AirInstrument * clone()const;
};


#endif //ASSIGNMENTA_PROFESSIONELL_H
