//
// Created by Eris on 3/20/2018.
//

#ifndef UNTITLED2_AFN_H
#define UNTITLED2_AFN_H

#include <iostream>

class AFN {
    int isword; //are valoarea 0->cuvantul nu apartine si 1->cuvantul apartine
    int stare; //starea curenta
    int nrs; //numar stari totale
    int nrf; //numar stari finale
    int nra; //numar litere alfabet
    int nrt; //numar tranzitii
    int *F; //starile finale
    char *A; //alfabetul
    struct tranzitii
    {int s1, s2; //starea1->litera->starea2
        char l;};
    tranzitii *T; //tranzitiile
public:
    AFN(); //constructor
    ~AFN(); //destructor
    bool Verifica(int poz, int stare, char *cuv);
};


#endif //UNTITLED2_AFN_H
