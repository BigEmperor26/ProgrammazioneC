#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "dati.h"
#define K 2
using namespace std;

int main()
{
    Tnodo * silos[N];
    Tparcheggio parcheggio;
    for(int i=0;i<N;i++){
        silos[i] = NULL;
    }
    for(int i=0;i<K;i++){
        creaParcheggio(&parcheggio);
        addParcheggio(silos,parcheggio);
    }
    for(int i=0;i<N;i++){
        printf("Lista numero %d\n",i);
        stampaLista(silos[i]);
    }
    return 0;
}
