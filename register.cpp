//
// Created by root on 2016-04-12.
//

#include "register.h"
#include <typeinfo>
#include <algorithm>
using namespace std;
Register::Register()
{
    this->capacitet=1;
    this->antalDeltagare=0;
    this->deltagarLista  = new deltagare*[this->capacitet];
}

Register::Register(int capacity)
{
    this->capacitet = capacity;
    this->antalDeltagare=0;
    this->deltagarLista  = new deltagare*[this->capacitet];
}

Register::Register(const Register& orgin)
{
    this->capacitet = orgin.capacitet;
    this->antalDeltagare=orgin.antalDeltagare;
    this->deltagarLista = new deltagare*[this->capacitet];
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        if(typeid(*orgin.deltagarLista[i])==typeid(professionell))
        {
            this->deltagarLista[i]= new professionell(*((professionell*)orgin.deltagarLista[i]));
        }
        else
        {
            this->deltagarLista[i]= new motionar(*((motionar*)orgin.deltagarLista[i]));
        }

    }
}

Register::~Register()
{
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        delete this->deltagarLista[i];

    }
    delete[] this->deltagarLista;

}

Register& Register::operator=(const Register &orgin)
{
    if(this != &orgin)
    {
            for (int i = 0; i < this->antalDeltagare; i++) {
                delete this->deltagarLista[i];
            }
            delete[] this->deltagarLista;

            this->antalDeltagare = orgin.antalDeltagare;
            this->capacitet = orgin.capacitet;
            this->deltagarLista = new deltagare *[this->capacitet];
            for (int i = 0; i < this->antalDeltagare; i++) {
                this->deltagarLista[i] = orgin.deltagarLista[i]->clone();
            }

    }
    return *this;
}

void Register::nyProfessionellDeltagare(string namn, string kon, string klubb, int aktivaPerioder)
{
    if(this->antalDeltagare < this->capacitet)
    {
        this->deltagarLista[this->antalDeltagare] = new professionell(namn, kon, klubb, aktivaPerioder);
        this->antalDeltagare++;
    }
    else
    {
        expand();
        ;
    }
}

void Register::nyMotionarDeltagare(string namn, string kon, int gammal)
{
    if(this->antalDeltagare < this->capacitet)
    {
        this->deltagarLista[this->antalDeltagare] = new motionar(namn, kon, gammal);
        this->antalDeltagare++;
    }
    else
    {
        expand();
        ;
    }
}

int Register::antaletDeltagare() const
{
    return this->antalDeltagare;
}

int Register::antalMotionarer() const
{
    int counter=0;
    if(this->antaletDeltagare() > 0)
    {
        if(this->antaletDeltagare() == 1)
        {
            if (typeid(this->deltagarLista[0]) == typeid(motionar))
            {
                for (int i = 0; i < this->antaletDeltagare(); i++)
                {
                    if (typeid(*this->deltagarLista[i]) == typeid(motionar))
                    {
                        counter++;
                    }
                }
            }
        }
        if(this->antaletDeltagare() > 1)
        {
            for (int i = 0; i < this->antaletDeltagare(); i++)
            {
                if (typeid(*this->deltagarLista[i]) == typeid(motionar))
                {
                    counter++;
                }
            }
        }
    }
    return counter;
}

int Register::antalProffs() const
{
    int counter=0;
    if(this->antaletDeltagare() > 0)
    {
        if(this->antaletDeltagare() == 1)
        {
            if (typeid(this->deltagarLista[0]) == typeid(professionell))
            {
                for (int i = 0; i < this->antalDeltagare; i++)
                {
                    if (typeid(*this->deltagarLista[i]) == typeid(professionell))
                    {
                        counter++;
                    }
                }
            }
        }
        if(this->antaletDeltagare() > 1)
        {
            for (int i = 0; i < this->antalDeltagare; i++)
            {
                if (typeid(*this->deltagarLista[i]) == typeid(professionell))
                {
                    counter++;
                }
            }
        }
    }
    return counter;
}

void Register::AllaDeltagare(string *array)
{
    for (int i = 0; i < this->antaletDeltagare() ; ++i)
    {
      array[i] = this->deltagarLista[i]->toString();
    }
}

void Register::AllaProffs(string *array)
{
    int p = 0;
    if(this->antaletDeltagare() == 1)
    {
        if(typeid(*this->deltagarLista[0]) == typeid(professionell))
        {
            array[p] = this->deltagarLista[0]->toString();
            p++;
        }
    }
    if(this->antaletDeltagare() > 1)
    {
        for (int i = 0; i < this->antaletDeltagare() ; ++i)
        {
            if(typeid(*this->deltagarLista[i])== typeid(professionell))
            {
                array[p] = this->deltagarLista[i]->toString();
                p++;
            }
        }
    }
}

void Register::AllaMotionarer(string *array)
{
    int q=0;
    if(this->antaletDeltagare() == 1)
    {
        if(typeid(*this->deltagarLista[0]) == typeid(motionar)) //Bugg.
        {
            for (int i = 0; i < this->antaletDeltagare(); ++i)
            {
                array[q] = this->deltagarLista[0]->toString();
                q++;
            }
        }
    }
    if(this->antaletDeltagare() > 1)
    {
        for (int i = 0; i < this->antaletDeltagare() ; ++i)
        {
            if(typeid(*this->deltagarLista[i])== typeid(motionar))
            {
                array[q] = this->deltagarLista[i]->toString();
                q++;
            }
        }
    }
}

void Register::rmDeltagare(const string Uniktnamn)
{

    for (int i = 0; i < this->antaletDeltagare() ; ++i)
    {

        if(this->deltagarLista[i]->getNamn() == Uniktnamn )
        {
            if(this->antaletDeltagare() == 1)
            {
                delete this->deltagarLista[0];
                this->deltagarLista[0] = nullptr;
                this->antalDeltagare--;
            }
            if(this->antaletDeltagare() > 1)
            {
                this->deltagarLista[i]->setNamn( this->deltagarLista[this->antaletDeltagare() - 1]->getNamn());
                this->deltagarLista[i]->setKon( this->deltagarLista[this->antaletDeltagare() - 1]->getKon());
                delete this->deltagarLista[this->antaletDeltagare() - 1];
                this->deltagarLista[this->antaletDeltagare()-1]= nullptr;
                this->antalDeltagare--;
            }
        }
    }
}


void Register::setProffsActiveYears(int yearInService, string namn)
{
    professionell* ptr2Human= nullptr;
    for (int i = 0; i < this->antaletDeltagare() ; ++i)
    {
        ptr2Human = dynamic_cast<professionell*>(this->deltagarLista[i]);
        if(ptr2Human != NULL && this->deltagarLista[i]->getNamn() == namn)
        {
            ptr2Human->setNrOfActiveSeassons(yearInService);
        }
    }

}

/*
int Register::getProffsActiveYears(string namn)
{
    professionell* ptr2Human= nullptr;
    for (int i = 0; i < this->antaletDeltagare() ; ++i)
    {
        ptr2Human = dynamic_cast<professionell*>(this->deltagarLista[i]);
        if(ptr2Human != NULL && this->deltagarLista[i]->getNamn() == namn)
        {
            return ptr2Human->getNrOfActiveSeassons();
        }
    }
    return -1;
}
*/ //debug only

void Register::expand()
{
    deltagare** tmpPtr=new deltagare*[this->antalDeltagare];
    motionar* Wptr= nullptr;
    professionell* Rptr= nullptr;
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        if(typeid(*this->deltagarLista[i]) == typeid(motionar))
        {
            Wptr = dynamic_cast<motionar*>(this->deltagarLista[i]);
            tmpPtr[i]= Wptr;
            delete this->deltagarLista[i];
        }
        if(typeid(*this->deltagarLista[i]) == typeid(professionell))
        {
            Rptr = dynamic_cast<professionell*>(this->deltagarLista[i]);
            tmpPtr[i]= Wptr;
            delete this->deltagarLista[i];
        }

    }

    delete[] this->deltagarLista;
    this->deltagarLista= new deltagare*[this->capacitet+5];
    this->capacitet += 5;

    for (int i = 0; i < this->antalDeltagare ; ++i)
    {   //              deltagare         vs.       motionar
        //typeid(tmpPtr).name() + typeid(motionar).name();
        if(typeid(tmpPtr[i]) == typeid(motionar))
        {
            Wptr = dynamic_cast<motionar*>(tmpPtr[i]);


        }
        if(typeid(tmpPtr[i]) == typeid(professionell))
        {
            Rptr = dynamic_cast<professionell*>(tmpPtr[i]);


        }

    }
}
//sorting relevant
/*
template <typename T>//only one function at a time.
void quickSort(T arr[], int start, int end)
{
    if(start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }

}

template <typename T>
int partition(T theArray[], int start, int end)
{
    T pivotValue = theArray[start];
    int pivotPos=start;
    for(int i=start+1; i<=end;i++)
    {
        if(theArray[i]<pivotValue)
        {
            swapI(theArray[i], theArray[pivotPos+1]);
            swapI(theArray[pivotPos], theArray[pivotPos+1]);
            pivotPos++;
        }
    }
    return pivotPos;
}
 */
bool Register::operator<(const Register &orgin)
{
    bool flag= false;
    //
    return flag;
}

void Register::sortingByNames(void)
{
    //quicksort algorithm by C. A. R. Hoare, 1960    deltagare *orgin, int start, int end

}

