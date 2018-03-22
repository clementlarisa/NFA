
//
// Created by Eris on 3/20/2018.
//

#include "AFN.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream in("AFN.in");

//constructor
AFN::AFN()
{
    in >> nume;
    in >> nra;//numarul literelor din alfabet

    A = new char[nra];//aloc spatiu

    for (int i = 0; i < nra; i++)
        in >> A[i];//citesc litera cu litera

    in >> nrs;//numarul starilor overall
    in >> starei;//starea de start
    in >> nrf;//numarul starilor finale

    F = new int[nrf];//aloc

    for (int i = 0; i < nrf; i++)
        in >> F[i];//citesc fiecare stare finala

    in >> nrt;//numarul de tranzitii

    T = new tranzitii[nrt];//imi aloc spatiu

    //citesc tranzitiile sub forma (stare1 litera stare2)
    for (int i = 0; i < nrt; i++)
        in >> T[i].s1 >> T[i].l >> T[i].s2;

    //initializez starea curenta cu 0
    stare = 0;

    //initializez variabila auxiliara isword cu 0
    isword = 0;
}

//destructor
AFN::~AFN()
{
    delete[]F;
    delete[]A;
    delete[]T;
}

//metoda prin care afisez pe ecran datele din fisierul de intrare
void AFN:: PrintInstructions()
{
    cout << "\nIn fisierul 'AFN.in' sunt introduse, in ordine:";
    cout << "\nAutomatul: " << nume;
    cout << "\nNr. litere alfabet: " << nra;
    cout << "\nLiterele alfabetului: ";
    for(int i = 0; i < nra; i++)
        cout << A[i] << " ";
    cout << "\nNr. stari totale: " << nrs;
    cout << "\nStarea initiala: " << starei;
    cout << "\nNr. stari finale: " << nrf;
    cout << "\nStarile finale: ";
    for(int i = 0;i < nrf; i++)
        cout << F[i] << " ";
    cout << "\nNr. tranzitii: " << nrt;
    cout << "\nTranzitiile (stare1 litera stare2):\n";
    for(int i = 0 ; i < nrt; i++)
    {cout << T[i].s1 << "-" << T[i].l << "->" << T[i].s2;
        cout << endl;}
}

//metoda pentru verificarea acceptarii cuvantului vid
bool AFN::CheckLambda()
{
    for(int i = 0; i < nrf; i++)
        if(starei == F[i])
            return true;//daca starea initiala este si finala
    return false;
}

//metoda de verificare a cuvantului dat pe care o apelez in main()
bool AFN::CheckWord(char *cuv)
{
    if(CheckLetters(cuv) == true);//daca toate literele cuvantului se gasesc in alfabet
    if(CheckAutomata(0,0,cuv) == true)
        return true;//daca ajunge intr-o stare finala
    return false;}

//metoda cu care verific daca literele cuvantului dat fac parte din alfabet
//parcurg cuvantul si elimin prima aparitie a fiecarei litere din A -> vectorul alfabet
bool AFN::CheckLetters(char *cuv)
{
    size_t found;
    for(int i = 0; i < strlen(cuv); i++)
    {
        string copy = A;
        found = copy.find(cuv[i]);//va returna pozitia pe care se gaseste litera cuvantului in copia lui A
        //in caz contrar, va returna npos
        if(found == string::npos)
            return false; //deja am gasit o litera stray, deci cuvantul nu poate fi verificat
    }
    return true;
}

//metoda functioneaza pe principiul de backtracking in cuvantul dat
//pozitia initiala este 0, starea este 0
bool AFN::CheckAutomata(int poz, int stare, char *cuv)
{
    //daca am ajuns la finalul cuvantului si nu am depasit numarul de stari
    if ( (poz == strlen(cuv)) && (stare <= nrs)) {
        //verific daca ma aflu intr-o stare finala
        for (int i = 0; i < nrf; i++)
            if (stare == F[i])
                isword = 1;//retin ca a existat posibilitatea sa ajung intr-o stare finala
    }//dar daca mai am litere in cuvant
    else
    {
        for (int i = 0; i < nrt; i++)
        {
            //verific daca starea mea curenta este vreo 'stare1' in alt triplet
            //si daca din ea pot sa plec cu litera pe care ma aflu intr-o 'stare2'
            //daca da, apelez metoda pentru urmatoarea litera si starea 'stare2' din tripletul corespunzator
            if ( (T[i].s1 == stare) && (T[i].l == cuv[poz]) )
                CheckAutomata(poz+1, T[i].s2, cuv);
        }
        if (isword == 1)//daca am ajuns intr-o stare finala, cuvantul e Ok
            return true;
        return false;//altfel, nu
    }
}
