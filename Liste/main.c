#include <stdio.h>
#include <stdlib.h>
//#include "Liste.h"

struct EL {
    int info;
    struct EL *next;
};
typedef struct EL ElemLista;
typedef ElemLista *ListadiInt;//puntatore ad una Lista
typedef enum boolean{false=0,true=1}boolean;//definizone di un tipo boolean

void init();
boolean listavuota(ListadiInt Lista);//non è necessario il passaggio per indirizzo
void stampa(ListadiInt Lista);//non è necessario il passaggio per indirizzo
//inserimento ed eliminazione restituiscono 1 se è andato a buon fine, 0 altrimenti ;)
int inserisci_coda(ListadiInt *Lista, int elem);//passato per indirizzo ovviamente
int inserisci_testa(ListadiInt *Lista, int elem);//passato per indirizzo ovviamente
int cancella_testa();
int cancella_coda();

//int inserisci(ListadiInt *Lista,int elem, int posizione); ancora da implementare

//void ricerca();
//void estrai();
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
