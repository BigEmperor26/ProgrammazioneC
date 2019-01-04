#ifndef __DATI__
#define __DATI__
#include <iostream>
#include <cstdlib>
#define DIM 2
using namespace std;

typedef enum Trichiesta {WEB,TELEFONO,UFFICIO}Trichiesta;

typedef struct Tordine{
    char materiale[20];
    int quantita;
    float prezzo;
    Trichiesta tipoRichiesta;
    Tordine (){
        materiale[0]='\0';
        quantita=-1;
        prezzo=-1.00;    
    }
    void stampa(){
        printf("%s ",materiale);
        printf("QTA =%d ",quantita);
        switch (tipoRichiesta){
            case 0: printf("(WEB)"); break;
            case 1: printf("(TELEFONO)"); break;
            case 2: printf("(UFFICIO)"); break;    
        }
        printf(" prezzo=%f\n",prezzo);    
    }   
}Tordine;

typedef struct Tnodo{
    Tordine dato;
    Tnodo* next;
    Tnodo* prev;
    Tnodo(){
        next=NULL;  prev=NULL;    
    }
    Tnodo(Tordine o, Tnodo* n,Tnodo* p){
        dato=o;
        next=n; prev=p;     
    }
    void stampa(){
        dato.stampa();    
    }
}Tnodo;

void newOrdine(Tordine* o);
void addOrdine(Tnodo* neg[],int dim,Tordine o);
Tnodo* inserFirst(Tnodo* neg,Tordine o);
void stampaNegozi(Tnodo* neg[],int dim);
void stampa(Tnodo* neg);
Tordine cercaOrdine(Tnodo * neg,int dim);
#endif
