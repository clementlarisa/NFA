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
    //daca am terminat cuvantul si nu am depasit numarul de stari
    if ((poz==strlen(cuv))&&(stare<=nrs))
    {
        //verific daca ma aflu intr-o stare finala
        for (int i=0; i<nrf; i++)
            //daca ma aflu "exista" primeste 1, adica cuvantul procesat este OK (variabila exista imi este necesara pentru
            //ca fiind un backtracking, ar fi incercat toate posibilitatile chiar daca nu mai era nevoie (adica cazul cand cuvantul
            //este OK nu ar fi fost luat in seama, acel return doar terminandu-mi apelul recursiv si ducandu-ma la
            //instructiunea din varful stivei))
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
            //daca exista este 1, nu il las sa se mai apeleze recursiv, ci ii opresc orice apel recursiv curent sau
            //aflat pe stiva returnand true, astfel fortandu-l sa se termine
            if (isword==1)
                return true;
            //daca if-ul de mai sus nu este executat, testez daca starea mea curenta si litera curenta din cuvant se afla
            //in vreun triplet, iar in caz afirmativ backtracking-ul continua
            if ((T[i].s1==stare)&&(T[i].l==cuv[poz]))

                Verifica(poz+1, T[i].s2,cuv);
        }
        //daca backtracking-ul s-a terminat fara ca "executa" sa se modifice din 0 in 1, inseamna ca nu este OK cuvantul
        //procesat, deci returnam false;
        return false;
    }
}
