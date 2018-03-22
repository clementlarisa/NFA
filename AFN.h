
//
// Created by Eris on 3/20/2018.
//

#ifndef UNTITLED2_AFN_H
#define UNTITLED2_AFN_H

class AFN {
    int starei;
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
    char nume[2];//numele automatului de care am nevoie si in main()

    AFN(); //constructor
    ~AFN(); //destructor

    //metoda de afisare a continutului din fisierul de intrare
    void PrintInstructions();

    //metoda de verificare a apartenentei cuvantului vidul
    bool CheckLambda();

    //metoda de verificare a apartenentei cuvantului
    bool CheckWord(char*);

    //metoda de verificare a formarii cuvantului din literele alfabetului
    bool CheckLetters (char*);

    //metoda ce functioneaza pe principiul backtracking
    //returneaza true daca acel cuvant dat apartine de L(automat)
    //si false, altfel

    bool CheckAutomata(int, int, char*);
};


#endif //UNTITLED2_AFN_H
