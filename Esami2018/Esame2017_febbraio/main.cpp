#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "dati.h"
#define K 20
using namespace std;

int main()
{
    Tstack officina[3];
    Triparazione intervento;
    for(int i=0;i<K;i++){
        creaRiparazione(&intervento);
        addRiparazione(&officina[rand()%3],intervento);
    }
    for(int i=0;i<3;i++){
        officina[i].stampa();
    }
    Triparazione tmp = selectRiparazione(officina,3);
    tmp.stampa();
    Tcassa cassa = incassoEFiltro(officina,3,Tlavoro(rand()%3));
    return 0;
}
