#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "dati.h"
#define K 20
using namespace std;

int main()
{
    Tbiglietto biglietto;
    Tbiglietteria biglietteria;
    for(int i=0;i<K;i++){
        creaBiglietto(&biglietto);
        inserisciBiglietto(&biglietteria,biglietto);
    }
    biglietteria.stampa();
    int n=0;
    Tn_mezzo m = cercaMezzo(biglietteria);
    switch (m.mezzo){
            case 0 : printf("TRENO "); break;
            case 1 : printf("AEREO "); break;
            case 2 : printf("TAXI "); break;
    }
    printf("\n%d\n",m.n);
    printf("%f",m.n/float(biglietteria.numBiglietti));
    return 0;
}
