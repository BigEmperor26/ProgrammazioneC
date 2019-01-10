#include <iostream>
#include <cstdlib>
#include "dati.h"
using namespace std;

void creaVeicolo(Tveicolo* v){
    v->tipo=Ttipo(rand()%3);
    do{
        printf("cilindrata: ");
        scanf("%d",&(v->cil));
    }while( v->cil<900 || v->cil>4000 );
    v->kw = v->cil/17.00;
    printf("marca: ");
    scanf("%s",v->marca);
}
void addVeicolo(TcodaFIFO* p,Tveicolo v){
    if(p->n < p->dim){
        p->s[p->tail]=v;
        p->tail = (p->tail +1) % p->dim;
        p->n++;
    }
}
void stampaVeicolo(TcodaFIFO* p){
    p->stampa();
}

void delAuto(TcodaFIFO* p,int c){
    for(int i=0;i<p->n;i++){
        Tveicolo tmp=p->s[(p->head+i)%p->dim];
        if(tmp.cil < c){
            write_file("auto.txt",tmp);
        }
    }
    p->n=0;
    p->head=0;
    p->tail=0;
}

void write_file(char nome_file[],Tveicolo v){
    FILE* fp=fopen(nome_file,"w");
    if(fp==NULL){
        fprintf(stderr,"dati non salvati correttamente");
    }else{
        fprintf(fp,"%s",v.marca);
        fprintf(fp,"CILINDRATA=%d ",v.cil);
        fprintf(fp,"KW=%f\n",v.kw);
    }
}
