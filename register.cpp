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
//needs expansion part
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
//needs expansion part
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
        this->deltagarLista[this->antalDeltagare] = new motionar(namn, kon, gammal);
        this->antalDeltagare++;
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
                //stoppa allt.
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
    //skapa tmp behållare för klass obj ptr
    deltagare** tmp= new deltagare*[this->antaletDeltagare()];

    //copy: från this[] till tmp[]
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        tmp[i] = this->deltagarLista[i]->clone();
    }
    //rm: this[]
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        delete this->deltagarLista[i];
    }
    delete[] this->deltagarLista;
    //new: större this[]. gör  capacity större.
    this->deltagarLista= new deltagare*[this->capacitet+3];
    this->capacitet += 3;
    //copy: tmp[] till this[]
    for (int i = 0; i < this->antalDeltagare ; ++i)
    {
        this->deltagarLista[i]= tmp[i]->clone();
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
    ;
    return flag;
}

void Register::sortingByNames(void)
{
    //quicksort algorithm by C. A. R. Hoare, 1960    deltagare *orgin, int start, int end
    this->quickSort(*this, 0, this->antalDeltagare);

}


void Register::quickSort(Register& orgin, int start, int end)
{
    if(start < end)
    {
        int pivot = partition(orgin, start, end);
        quickSort(orgin, start, pivot-1);
        quickSort(orgin, pivot+1, end);
    }

}

int Register::partition(Register& orgin, int start, int end)
{
    string pivotValue = orgin.deltagarLista[start]->getNamn();
    int pivotPos=start;
    for(int i=start+1; i<=end;i++)
    {
        if(orgin.deltagarLista[i]->getNamn()<pivotValue)
        {
            swapI(orgin, i, orgin, pivotPos+1);
            swapI(orgin, i, orgin, pivotPos+1);
            pivotPos++;
        }
    }
    return pivotPos;
}

void Register::swapI(Register& source,int index1, Register& orgin , int index2)
{
    deltagare* tmp = source.deltagarLista[index1]->clone();
    delete source.deltagarLista[index1];
    source.deltagarLista[index1] = orgin.deltagarLista[index2]->clone();
    orgin.deltagarLista[index2] = tmp;
}


