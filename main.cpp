#include <iostream>
#include <fstream>
#include <cstring>
#include "AFN.h"

using namespace std;

int main()
{
    cout << "Cuvantul vid => 'vid'\nIntroduceti cuvantul: ";

    char cuvant[20];

    char vid[]="vid";

    cin >> cuvant;

    AFN automat;

    automat.PrintInstructions();

    if( strcmp (vid,cuvant) == 0 )
    {
        if( automat.CheckLambda() == true )
            cout << "\nCuvantul vid apartine de L(" << automat.nume << ").\n";
        else
            cout << "\nCuvantul vid nu apartine de L(" << automat.nume << ").\n";
    }
    else
    {
        if( automat.CheckWord(cuvant) == true )
            cout << "\nCuvantul apartine de L(" << automat.nume << ").\n";
        else
            cout << "\nCuvantul nu apartine de L(" << automat.nume << ").\n";
    }

    return 0;
}
