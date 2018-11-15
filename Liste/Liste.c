#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

//init ok!
void init(ListadiInt *Lista){//passaggio per indirizzo del puntatore alla lista
    *Lista=NULL;//la lista deve essere vuota
}
//listavuota ok!
boolean listavuota(ListadiInt Lista){
    if(Lista==NULL) { return true; }
    return false;
}
//stampa ok!
void stampa(ListadiInt Lista){//attenzione, anche se Lista è passato per parametro, i valori della lista si trovano nello HEAP, quindi sono modificabili
    while(!listavuota(Lista)){
        printf("%d\n",Lista->info);
        //Lista->info=0; esempio di modifica
        Lista=Lista->next;
    }
}
//inserisci_test ok!
int inserisci_testa(ListadiInt *Lista,int elem){
    ElemLista *tmp=malloc(sizeof(ElemLista));
    tmp->info=elem;
    tmp->next=*Lista;
    *Lista=tmp;
    return 1;
}
//inserisci_coda ok!
int inserisci_coda(ListadiInt *Lista,int elem){
    ListadiInt tmp = *Lista;
    if(listavuota(*Lista)){
        (tmp)=malloc(sizeof(ElemLista));
        (tmp)->info=elem;
        (tmp)->next=NULL;
        *Lista=tmp;
    }else{
        while(!listavuota(tmp->next)){
            (tmp)=(tmp)->next;
        }
        (tmp)->next=malloc(sizeof(ElemLista));
        (tmp)->next->info=elem;
        (tmp)->next->next=NULL;
    }
    /* soluzione alternativa in ricorsiva
    if(listavuota(*Lista)){
        ElemLista *tmp=malloc(sizeof(ElemLista));
        tmp->info=elem;
        tmp->next=NULL;
        *Lista=tmp;
    }else{
        inserisci_coda(&((*Lista)->next),elem);
    }*/
    return 1;
}
//ancora da implementare correttamente
/*
int inserisci(ListadiInt *Lista,int elem, int posizione){
    ListadiInt tmp=*Lista;
    int i=0;
    for(i=0;i<posizione-1;i++){//controllo che la posizione non sia più grande della lista
        if(!listavuota(tmp->next)){
           tmp=tmp->next;
        }else{
            return 1;
        }
    }
    tmp=*Lista;
    for(i=0;i<posizione-1;i++){//???????

    }
}*/

int cancella_testa(ListadiInt *Lista){
    if(listavuota(*Lista)){
        return 0;
    }else{
        ElemLista *tmp; //copia della testa
        tmp=(*Lista)->next;
        free((*Lista));
        (*Lista)=tmp;
    }
    return 1;
}
int cancella_coda(ListadiInt *Lista){
    ListadiInt tmp=*Lista;
    if(listavuota(*Lista)){
        return 0;
    }else{
        while(!listavuota(tmp->next->next)){
            (tmp)=(tmp)->next;
        }
        free(tmp->next);
        tmp->next=NULL;
    }
    return 1;
}
