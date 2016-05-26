//
// Created by Roderik Bauhn on 2016-04-12.
//

#include "register.h"
#include <typeinfo>
using namespace std;
Register::Register()
{
    this->capacitet=1;
    this->antalInstrument=0;
    this->InstrumentLista  = new Instrument*[this->capacitet];
}

Register::Register(int capacity)
{
    this->capacitet = capacity;
    this->antalInstrument=0;
    this->InstrumentLista  = new Instrument*[this->capacitet];
}

Register::Register(const Register& orgin)
{
    this->capacitet = orgin.capacitet;
    this->antalInstrument=orgin.antalInstrument;
    this->InstrumentLista = new Instrument*[this->capacitet];
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        if(typeid(*orgin.InstrumentLista[i])==typeid(AirInstrument))
        {
            this->InstrumentLista[i]= new AirInstrument(*((AirInstrument*)orgin.InstrumentLista[i]));
        }
        else
        {
            this->InstrumentLista[i]= new StringInstrument(*((StringInstrument*)orgin.InstrumentLista[i]));
        }

    }
}

Register::~Register()
{
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        delete this->InstrumentLista[i];

    }
    delete[] this->InstrumentLista;

}

Register& Register::operator=(const Register &orgin)
{
    //uses clone() to get data transfered correct. We are using two subclasses here.
    if(this != &orgin)
    {
            for (int i = 0; i < this->antalInstrument; i++)
            {
                delete this->InstrumentLista[i];
            }
            delete[] this->InstrumentLista;

            this->antalInstrument = orgin.antalInstrument;
            this->capacitet = orgin.capacitet;
            this->InstrumentLista = new Instrument *[this->capacitet];
            for (int i = 0; i < this->antalInstrument; i++) {
                this->InstrumentLista[i] = orgin.InstrumentLista[i]->clone();
            }

    }
    return *this;
}

void Register::expand()
{
    //skapa tmp behållare för klass obj ptr
    Instrument** tmp= new Instrument*[this->antaletInstrument()];

    //copy: från this[] till tmp[]
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        tmp[i] = this->InstrumentLista[i]->clone();
    }
    //rm: this[]
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        delete this->InstrumentLista[i];
    }
    delete[] this->InstrumentLista;
    //new: större this[]. gör  capacity större.
    this->InstrumentLista= new Instrument*[this->capacitet+3];
    this->capacitet += 3;
    //copy: tmp[] till this[]
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        this->InstrumentLista[i]= tmp[i]->clone();
    }
    //clean tmp
    for (int i = 0; i < this->antalInstrument ; ++i)
    {
        delete tmp[i];
    }
    delete[] tmp;
}

/////////////////////////////////////////////////////


////////////////////////////////////////////////////

//A.
void Register::nyttLuftInstrument(string namn, bool trablas, bool blackblas)
{
    if(this->antalInstrument < this->capacitet)
    {
        this->InstrumentLista[this->antalInstrument] = new AirInstrument(namn, trablas, blackblas);
        this->antalInstrument++;
    }
    else
    {
        expand();
        this->InstrumentLista[this->antalInstrument] = new AirInstrument(namn, trablas, blackblas);
        this->antalInstrument++;
    }
}
//A.
void Register::nyttStrangInstrument(string namn,int numberOfStrings, bool knapp, bool bowStroke)
{
    if(this->antalInstrument < this->capacitet)
    {
        this->InstrumentLista[this->antalInstrument] = new StringInstrument(namn,numberOfStrings,knapp, bowStroke);
        this->antalInstrument++;
    }
    else
    {
        expand();
        this->InstrumentLista[this->antalInstrument] = new StringInstrument(namn,numberOfStrings,knapp, bowStroke);
        this->antalInstrument++;
    }
}
//B.
int Register::antaletInstrument() const
{
    return this->antalInstrument;
}
//B.
void Register::AllaInstrument(string *array) const
{
    for (int i = 0; i < this->antaletInstrument() ; ++i)
    {
      array[i] = this->InstrumentLista[i]->toString();
    }
}
//C.
int Register::antalStrangInstrument() const
{
    int counter=0;
    if(this->antaletInstrument() > 0)
    {
        if(this->antaletInstrument() == 1)
        {
            if (typeid(this->InstrumentLista[0]) == typeid(StringInstrument))
            {
                for (int i = 0; i < this->antalInstrument; i++)
                {
                    if (typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
                    {
                        counter++;
                    }
                }
            }
        }
        if(this->antaletInstrument() > 1)
        {
            for (int i = 0; i < this->antalInstrument; i++)
            {
                if (typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
                {
                    counter++;
                }
            }
        }
    }
    return counter;
}
//C.
void Register::AllaStrangInstrument(string *array) const
{
    int q=0;
    if(this->antaletInstrument() == 1)
    {
        if(typeid(*this->InstrumentLista[0]) == typeid(StringInstrument))
        {
            for (int i = 0; i < this->antaletInstrument(); ++i)
            {
                array[q] = this->InstrumentLista[0]->toString();
                q++;
            }
        }
    }
    if(this->antaletInstrument() > 1)
    {
        for (int i = 0; i < this->antaletInstrument() ; ++i)
        {
            if(typeid(*this->InstrumentLista[i])== typeid(StringInstrument))
            {
                array[q] = this->InstrumentLista[i]->toString();
                q++;
            }
        }
    }
}
//D.
int Register::antalLuftInstrument() const
{
    int counter=0;
    if(this->antaletInstrument() > 0)
    {
        if(this->antaletInstrument() == 1)
        {
            if (typeid(this->InstrumentLista[0]) == typeid(StringInstrument))
            {
                for (int i = 0; i < this->antaletInstrument(); i++)
                {
                    if (typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
                    {
                        counter++;
                    }
                }
            }
        }
        if(this->antaletInstrument() > 1)
        {
            for (int i = 0; i < this->antaletInstrument(); i++)
            {
                if (typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
                {
                    counter++;
                }
            }
        }
    }
    return counter;
}
//D.
void Register::AllaLuftInstrument(string *array) const
{
    int p = 0;
    if(this->antaletInstrument() == 1)
    {
        if(typeid(*this->InstrumentLista[0]) == typeid(AirInstrument))
        {
            array[p] = this->InstrumentLista[0]->toString();
            p++;
        }
    }
    if(this->antaletInstrument() > 1)
    {
        for (int i = 0; i < this->antaletInstrument() ; ++i)
        {
            if(typeid(*this->InstrumentLista[i])== typeid(AirInstrument))
            {
                array[p] = this->InstrumentLista[i]->toString();
                p++;
            }
        }
    }
}
//E.
string Register::AllstrangInstrumentInIntervall(int start, int end) const
 {
    stringstream ll;
    for (int i = 0; i < this->antaletInstrument() ; ++i)
    {
        if(typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
        {
            if ((dynamic_cast<StringInstrument*>(this->InstrumentLista[i]))->getNrOfStrings() >= start && (dynamic_cast<StringInstrument*>(this->InstrumentLista[i]))->getNrOfStrings() <= end)
            {
                ll << this->InstrumentLista[i]->toString();
            }
        }
    }
    return ll.str();
}
//F.
void Register::changeNrOfStrings(int nrOfStrings, string namn)
{
    for (int i = 0; i < this->antaletInstrument() ; ++i)
    {
        if(typeid(*this->InstrumentLista[i]) == typeid(StringInstrument))
        {
            if (this->InstrumentLista[i]->getNamn() == namn)
            {
                (dynamic_cast<StringInstrument*>(this->InstrumentLista[i]))->setNrOfStrings(nrOfStrings);
            }
        }
    }
}
// G   remove by overwriting with last place data. If one element empty data in place 0.
//FixCode 0x3 ::
void Register::rmInstrument(const string Uniktnamn)
{

    for (int i = 0; i < this->antaletInstrument() ; ++i)
    {

        if(this->InstrumentLista[i]->getNamn() == Uniktnamn )
        {
            if(this->antaletInstrument() == 1)
            {
                delete this->InstrumentLista[0];
                this->InstrumentLista[0] = nullptr;
                this->antalInstrument--;
            }
            if(this->antaletInstrument() > 1)
            {
                this->InstrumentLista[i]= this->InstrumentLista[this->antaletInstrument()-1]->clone();
                delete this->InstrumentLista[this->antaletInstrument() - 1];
                this->InstrumentLista[this->antaletInstrument()-1] = nullptr;
                this->antalInstrument--;
            }
        }
    }
}
