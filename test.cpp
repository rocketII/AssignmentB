//
// Created by Roderik Bauhn on 2016-04-22.
//
#include "register.h"
#include <iostream>
using namespace std;
int main(void)
{
    //below we test copy constructor, deep copy, operator=, expansion of array and so on...
    string* tmp= nullptr;
    //if Linux comment bellow and use valgrind, might need header
    //_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Register test;
    test.nyttLuftInstrument("blockflöjt",true,false);
    test.nyttStrangInstrument("fiol",7,true,false);
    cout << test.antaletInstrument()<<'\n';
    cout << test.antalLuftInstrument()<<'\n';
    cout << test.antalStrangInstrument()<<'\n';
    tmp = new string[test.antaletInstrument()];
    test.AllaInstrument(tmp);
    cout << "\nMusikInstrument-----------\n"<<endl;
    for (int i = 0; i < test.antaletInstrument() ; ++i)
    {
        cout<<tmp[i]<<endl;
    }
    cout << "\nBlåsInstrument-----------\n"<<endl;
    delete[] tmp;
    tmp = new string[test.antalLuftInstrument()];
    test.AllaLuftInstrument(tmp);
    for (int i = 0; i < test.antalLuftInstrument() ; ++i)
    {
        cout<<tmp[i]<<endl;
    }
    cout << "\nSträngInstrument-----------\n"<<endl;
    delete[] tmp;
    tmp = new string[test.antalStrangInstrument()];
    test.AllaStrangInstrument(tmp);
    for (int i = 0; i < test.antalStrangInstrument() ; ++i)
    {
        cout<<tmp[i]<<endl;
    }
    cout <<"\n----------------\n"<<endl;
    delete[] tmp;
    //test. copy constructor
    Register test2 = test;
    Register test3;
    //test. operator=().
    test3 = test;
    //test. deep copy if shallow copy removing source effects test3 data.
    cout <<"rm: from test"<<endl;
    test.rmInstrument("blockflöjt");
    test.rmInstrument("blockflöjt");
    test.rmInstrument("fiol");
    tmp = new string[test3.antaletInstrument()];
    test3.AllaInstrument(tmp);
    cout <<"rm: printing"<<endl;
    for (int i = 0; i < test3.antaletInstrument() ; ++i)
    {
        cout<<tmp[i]<<endl;
    }
    delete[] tmp;
    cout<<"\nExiting test suite\n"<<endl;
    return 0;
}
