//
// Created by root on 2016-04-12.
//

#ifndef ASSIGNMENTB_DELTAGARE_H
#define ASSIGNMENTB_DELTAGARE_H
#include <string>
#include <sstream>
//Ska vara abstrakt
using  namespace std;
class deltagare
{
private:
    string namn, kon;
public:
    deltagare(){};
    deltagare(const string &namn, const string &kon) : namn(namn), kon(kon) { }
    deltagare& operator=(const deltagare& orgin);
    virtual ~deltagare() { }
    deltagare(const deltagare& orgin);


    const string getNamn() const ;

    void setNamn(const string namn) ;

    const string getKon() const ;

    void setKon(const string kon) ;

    virtual string toStringSpecific(void)const =0;
    virtual deltagare* clone() const=0;
    string toString()const;

};


#endif //ASSIGNMENTB_DELTAGARE_H
