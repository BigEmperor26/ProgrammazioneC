#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "dati.h"
using namespace std;

void creaParcheggio(Tparcheggio* p){
    p->dataParcheggio = Tdata(rand()%32+1,rand()%13+1,rand()%3+2018);
    scanf("%s",p->nomeCliente);
    char tmp[20];
    tmp[0] = '\0';
    do{
        scanf("%s",tmp);
        if(strcmp(tmp,"BENZINA")){p->alimentazioneAuto = Talimentazione(0);}
        if(strcmp(tmp,"DIESEL")){ p->alimentazioneAuto = Talimentazione(1);}
        if(strcmp(tmp,"GPL")){ p->alimentazioneAuto = Talimentazione(2);}
    }while(!strcmp(tmp,"BENZINA") && !strcmp(tmp,"DIESEL") && !strcmp(tmp,"GPL"));
    p->importo = rand()% (2500 - 100 + 1) + 100;
    p->importo /= 100.00;
}
void addParcheggio(Tnodo* s[N], Tparcheggio p){
    int n = rand()% N;
    s[n] = insertLast(s[n],p);

}
Tnodo* insertLast(Tnodo* s,Tparcheggio p){
    if(s==NULL){
        return new Tnodo(p,NULL,NULL);
    }
    while(s->next!=NULL){
        s = s->next;
    }
    s->next = new Tnodo(p,s,NULL);
}
Tincasso incassoParcheggio(Tnodo* s){
    float i = 0;
    int n = 0;
    while(s!=NULL){
        i += s->data.importo;
        n++;
        s = s->next;
    }
    return Tincasso(i,n);
}
void salvaParcheggio(Tnodo* s[N],float minImporto){
    for(int i=0;i<N;i++){
        while(s[i]!=NULL){
            Tparcheggio data = readFirst(s[i]);
            s[i] = removeFirst(s[i]);
            if(data.importo < minImporto){
                FILE * fp = fopen("dati.txt","w");
                fprintf(fp,"[%u/%u/%u] %s %f\n",data.dataParcheggio.gg, data.dataParcheggio.mm, data.dataParcheggio.aa, data.nomeCliente, data.importo);
                fclose(fp);
            }
        }
    }
}
Tnodo* removeFirst(Tnodo* s){
    if(s==NULL){    return NULL;}
    s = s->next;
    delete s->prev;
    return s;
}
Tparcheggio readFirst(Tnodo* s){
    return s->data;
}
void stampaLista(Tnodo* s){
    while(s!=NULL){
        s->stampa();
        s = s->next;
    }
}

