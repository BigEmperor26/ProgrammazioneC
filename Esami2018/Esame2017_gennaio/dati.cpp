#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include "dati.h"
using namespace std;


void creaBiglietto(Tbiglietto* x){
    x->mezzo = Tmezzo(rand()%3);
    //scanf("%s",x->destinazione);
    strcpy(x->destinazione,"p");
    x->dataViaggio= Tdata(rand()%31 +1,rand()%12 +1,rand()% 3 +2012);
}


void inserisciBiglietto(Tbiglietteria * b, Tbiglietto x){
    int n=rand()%3;
    b->push(x,n);
}
Tn_mezzo cercaMezzo(Tbiglietteria b){
    int conta[3]={0,0,0};
    for(int i=0;i<3;i++){
        Tnodo* tmp = b.sportello[i];
        while(tmp!=NULL){
            if(b.sportello[i]->data.mezzo==TRENO){ conta[0]++;}
            if(b.sportello[i]->data.mezzo==AEREO){ conta[1]++;}
            if(b.sportello[i]->data.mezzo==TAXI){ conta[2]++;}
            tmp = tmp->next;
        }
    }
    if(conta[0] >= conta[1] && conta[0] >= conta[2] ){  return Tn_mezzo (TRENO,conta[0]);}
    if(conta[1] >= conta[0] && conta[1] >= conta[2] ){  return Tn_mezzo (AEREO,conta[1]);}
    if(conta[2] >= conta[1] && conta[2] >= conta[1] ){  return Tn_mezzo (TAXI,conta[2]);}
}

void salvaBiglietti(Tbiglietteria *b,Tmezzo m){
    for(int i=0;i<3;i++){
        while(!b->isEmpty(i)){
            Tbiglietto tmp = b->pop(i);
            if(tmp.mezzo == m){
                FILE* fp = fopen("biglietti.txt","w");
                fprintf(fp,"%d/",tmp.dataViaggio.gg);
                fprintf(fp,"%d/",tmp.dataViaggio.mm);
                fprintf(fp,"%d ",tmp.dataViaggio.aa);
                fprintf(fp,"%s\n",tmp.destinazione);
            }
        }
    }
}

