//
// Created by root on 2016-04-12.
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
}

/////////////////////////////////////////////////////


////////////////////////////////////////////////////

//1.
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
//1.
void Register::nyttStrangInstrument(string namn,int numberOfStrings, bool knapp, bool stroke)
{
    if(this->antalInstrument < this->capacitet)
    {
        this->InstrumentLista[this->antalInstrument] = new StringInstrument(namn,numberOfStrings,knapp, stroke);
        this->antalInstrument++;
    }
    else
    {
        expand();
        this->InstrumentLista[this->antalInstrument] = new StringInstrument(namn,numberOfStrings,knapp, stroke);
        this->antalInstrument++;
    }
}
//2.
int Register::antaletInstrument() const
{
    return this->antalInstrument;
}
//2.
void Register::AllaInstrument(string *array)
{
    for (int i = 0; i < this->antaletInstrument() ; ++i)
    {
      array[i] = this->InstrumentLista[i]->toString();
    }
}
//3.
int Register::antalStrangInstrument() const
{
    int counter=0;
    if(this->antaletInstrument() > 0)
    {
        if(this->antaletInstrument() == 1)
        {
            if (typeid(this->InstrumentLista[0]) == typeid(AirInstrument))
            {
                for (int i = 0; i < this->antalInstrument; i++)
                {
                    if (typeid(*this->InstrumentLista[i]) == typeid(AirInstrument))
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
                if (typeid(*this->InstrumentLista[i]) == typeid(AirInstrument))
                {
                    counter++;
                }
            }
        }
    }
    return counter;
}
//3.
void Register::AllaStrangInstrument(string *array)
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
                //after inserting two stringInstrumenst, changing one of them to lower stringsNumber, than run c segmentation fault.
                array[q] = this->InstrumentLista[i]->toString();
                q++;
            }
        }
    }
}
//4.
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
//4.
void Register::AllaLuftInstrument(string *array)
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
//5.
string Register::AllstrangInstrumentInIntervall(int start, int end)
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
//6.
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
// 7
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
                this->InstrumentLista[i]->setNamn( this->InstrumentLista[this->antaletInstrument() - 1]->getNamn());
                delete this->InstrumentLista[this->antaletInstrument() - 1];
                this->InstrumentLista[this->antaletInstrument()-1] = nullptr;
                this->antalInstrument--;
            }
        }
    }
}
