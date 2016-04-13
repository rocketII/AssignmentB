//
// Created by bps on 2016-04-11.
//
#include "register.h"
#include <iostream>

using namespace std;

int main(void)
{

    Register testA(1);
    testA.nyProfessionellDeltagare("Eric Holm", "Man","Malmö IF", 3 );
    testA.nyProfessionellDeltagare("Victoria Bergqvist", "Kvinna","Malmö IF", 3 );
    testA.nyMotionarDeltagare("Ulla", "kvinna", 13);
    testA.setProffsActiveYears(23, "Victoria Bergqvist");
    cout << "\nhello";
    return 0;
}
