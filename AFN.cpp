//
// Created by Eris on 3/20/2018.
//

#include "AFN.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructor
AFN::AFN()
{
    cout<<"Nr. litere alfabet: ";
    cin>>nra;
    A=new char[nra];
    cout<<"\nLiterele alfabetului: ";
    for (int i=0; i<nra; i++)
        cin>>A[i];
    cout<<"\nNr. stari totale: ";
    cin>>nrs;
    cout<<"\nNr. stari finale: ";
    cin>>nrf;
    F=new int[nrf];
    cout<<"\nStarile finale: ";
    for (int i=0; i<nrf; i++)
        cin>>F[i];

    cout<<"\nNr. tranzitii: ";
    cin>>nrt;
    T=new tranzitii[nrt];
    cout<<"\nTranzitiile (stare1 litera stare2): ";
    for (int i=0; i<nrt; i++)
        cin>>T[i].s1>>T[i].l>>T[i].s2;
    stare=0;
    isword=0;
}

//destructor
AFN::~AFN()
{
    delete[]F;
    delete[]A;
    delete[]T;
}

//functie care returneaza true => cuvantul apartine alfabetului
//si false in caz contrar
bool AFN::Verifica(int poz, int stare, char *cuv)
{
    if ((poz==strlen(cuv))&&(stare<=nrs))
    {
        for (int i=0; i<nrf; i++)
            if (stare==F[i])
            {
                isword=1;
                return true;
            }
    }
    else
    {
        for (int i=0; i<nrt; i++)
        {

            if (isword==1)
                return true;
            if ((T[i].s1==stare)&&(T[i].l==cuv[poz]))

                Verifica(poz+1, T[i].s2,cuv);
        }
        return false;
    }
}
