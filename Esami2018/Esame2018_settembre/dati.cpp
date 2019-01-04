#include <cstdlib>
#include <iostream>
#include "dati.h"
using namespace std;


void newOrdine(Tordine* o){
    o->tipoRichiesta = Trichiesta(rand()%3);
    do{
        scanf("%d",&(o->quantita));    
    }while(o->quantita<1 || o->quantita>20 );    
    o->prezzo = (rand()% (9999-1000+1)+1000)/100.00;
    scanf("%s",o->materiale); 
}

void addOrdine(Tnodo* neg[],int dim,Tordine o){
    int x=rand()%2;
    neg[x]=inserFirst(neg[x],o);    
}
Tnodo* inserFirst(Tnodo* neg,Tordine o){
    if(neg==NULL){  return new Tnodo(o,NULL,NULL);}
    Tnodo* tmp=new Tnodo(o,neg,NULL);
    return tmp;
}
void stampaNegozi(Tnodo* neg[],int dim){
    for(int i=0;i<dim;i++){
        printf("array numero %d : \n",i); 
        stampa(neg[i]);       
    }    
    
}
void stampa(Tnodo* neg){
    while(neg!=NULL){
        neg->stampa();
        neg=neg->next;    
    }    
}
Tordine cercaOrdine(Tnodo* neg,int dim){
    int max=cercamax();
    for(int i=0;i<dim;i++){
            
    }
}
