#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
int main()
{
    ListadiInt l;
    init(&l);
    inserisci_testa(&l,1);
    inserisci_testa(&l,2);
    inserisci_testa(&l,3);
    inserisci_testa(&l,4);
    inserisci_testa(&l,5);
    inserisci_testa(&l,6);
    inserisci_coda(&l,8);
    inserisci_coda(&l,9);
    cancella_testa(&l);
    cancella_coda(&l);
    //printf("\n%d",l->info);
    if(listavuota(l)) printf("Vuoto\n");
    stampa(l);
    stampa(l);
    //stampa(l);
    printf("Hello world!\n");
    return 0;
}
