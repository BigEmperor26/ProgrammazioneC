#include <cstdlib>
#include <iostream>
#include <cstring>
#include "dati.h"
using namespace std;

void creaSpedizione(Tspedizione* s){
    s->tipoPacco= Tpacco (rand()%3);
    do{
            printf("peso: ");
            scanf("%f",&(s->peso));
    }while(s->peso < 200.00 || s->peso > 5000.00 );
    if(s->tipoPacco > 0){
        s->assicurato=true;
    }else{
        s->assicurato=false;
    }
    printf("destinatario: ");
    scanf("%s",s->destinatario);
}

void addPacco(TcodaFIFO* p[],Tspedizione s){
    int n=rand()%3;
    //TcodaFIFO* tmp= new TcodaFIFO(p[n],s); implementazione LIFO
    //p[n]=tmp;
    //implementazione FIFO
    TcodaFIFO* tmp=p[n];
    if(tmp==NULL){
        TcodaFIFO* tmp= new TcodaFIFO(NULL,s);
        p[n]=tmp;
    }else{
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = new TcodaFIFO(NULL,s);
    }
}
void stampaSpedizioni_(TcodaFIFO *p){
    TcodaFIFO* tmp=p;
    while(tmp!=NULL){
        tmp->dato.stampa();
        tmp=tmp->next;
    }
}

void stampaSpedizioni(TcodaFIFO *p[], int n){
    for(int i=0;i<n;i++){
        printf("lista numero %d\n",i);
        stampaSpedizioni_(p[i]);
    }
}

TcodaFIFO* delPacchi(TcodaFIFO* p[],Tpacco tp,int n){
    for(int i=0;i<n;i++){
        delPacchi_(&p[i],tp);
    }
}

void delPacchi_(TcodaFIFO** p,Tpacco tp){
    TcodaFIFO* tmp=*p;
    while(tmp!=NULL){
        if(tmp->dato.tipoPacco == tp){
            FILE* fp=fopen("pacchiOrdinari","w");
            fprintf(fp,"%s PESO=%f\n",tmp->dato.destinatario,tmp->dato.peso);
            fclose(fp);
        }
        *p=tmp;
        tmp=tmp->next;
        delete *p;
    }
    *p=NULL;
}
