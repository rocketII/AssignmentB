//
// Created by bps on 2016-04-11.
//
#include "register.h"
//#include "system.h"
#include <iostream>

using namespace std;

int main(void)
{
    Register testSort(3);
    testSort.nyMotionarDeltagare("Bob", "Man", 12);
    testSort.nyMotionarDeltagare("Ross", "Man", 22);
    testSort.nyMotionarDeltagare("Arvid", "Man", 32);
    testSort.sortingByNames();
    cout << "\nhello quit";
    return 0;
}
