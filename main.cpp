#include <iostream>
#include <cstring>
#include "AFN.h"

using namespace std;

int main()
{
    cout<<"Cuvantul: ";
    char cuvant[20];
    cin>>cuvant;
    AFN automat;
    if(automat.Verifica(0,0,cuvant)==true)
        cout<<"\nCuvantul apartine alfabetului.\n";
    else cout<<"\nCuvantul nu apartine alfabetului.\n";
    return 0;
}
