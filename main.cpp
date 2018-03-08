#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    int ns, nsf;
    cout<<"Numarul de stari: ";
    cin>>ns;
    cout<<endl<<"Numarul de stari finale: ";
    cin>>nsf;
    char stari[ns], finale[nsf];
    cout<"Introduceti starile: ";
    for(int i=0;i<ns;i++)
        cin>>stari[i];
    cout<<endl<<"Introduceti starile finale: "
    for(int i=0;i<nsf;i++)
        cin>>finale[i];
    cout<<"Introduceti numarul de simboluri din alfabet: ";
    int na;
    cin>>na;
    char alfabet[na];
    for (int i=0;i<na;i++)
        cin>>alfabet[i];


    return 0;
}