#ifndef __DATI__
#define __DATI__

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#define MAXLENGTH 20

using namespace std;

typedef struct Tdata{
    unsigned int gg;
    unsigned int mm;
    unsigned int aa;
    Tdata(){
        gg=mm=aa=0;
    }
    Tdata(int _gg,int _mm,int _aa){
        gg=_gg;
        mm=_mm;
        aa=_aa;
    }
    void stampa(){
        printf("%u/%u/%u",gg,mm,aa);
    }
}Tdata;

typedef enum Tmezzo{TRENO,AEREO,TAXI}Tmezzo;

typedef struct Tbiglietto{
    Tdata dataViaggio;
    char destinazione[MAXLENGTH];
    Tmezzo mezzo;
    Tbiglietto(){
        destinazione[0]='\0';
        mezzo=Tmezzo(1);
    }
    void stampa(){
        dataViaggio.stampa();
        printf(" viaggio ");
        switch (mezzo){
            case 0 : printf("TRENO "); break;
            case 1 : printf("AEREO "); break;
            case 2 : printf("TAXI "); break;
        }
        printf("%s",destinazione);
    }
}Tbiglietto;

typedef struct Tnodo{
    Tbiglietto data;
    Tnodo* next;
    Tnodo(){
        next = NULL;
    }
    Tnodo(Tbiglietto x){
        data = x;
        next = NULL;
    }
    void stampa(){
        data.stampa();
    }
}Tnodo;

typedef struct Tbiglietteria{
    int numBiglietti;
    Tnodo* sportello[3];
    Tbiglietteria(){
        numBiglietti=0;
        for(int i=0;i<3;i++){ sportello[i]=NULL; }
    }
    void stampa(){
        for(int i=0;i<3;i++){
            Tnodo* tmp = sportello[i];
            while(tmp!=NULL){
                (*sportello[i]).stampa();
                printf("\t");
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    void push(Tbiglietto x,int n){
        Tnodo* tmp = new Tnodo(x);
        tmp->next = sportello[n];
        sportello[n] = tmp;
        numBiglietti++;
    }
    Tbiglietto pop(int n){
        Tnodo* tmp = sportello[n];
        Tbiglietto data = (*sportello[n]).data;
        sportello[n] = sportello[n]->next;
        delete tmp;
        numBiglietti--;
        return data;
    }
    Tbiglietto read(int n){
        Tbiglietto data = (*sportello[n]).data;
        return data;
    }
    bool isEmpty(int n){
        if(sportello[n]==NULL){ return true; }
        else{                   return false;}
    }
}Tbiglietteria;

typedef struct Tn_mezzo{
    Tmezzo mezzo;
    int n;
    Tn_mezzo(){
    n=-1;
    }
    Tn_mezzo(Tmezzo m, int c){
        mezzo=m;
        n=c;
    }
}Tn_mezzo;
void creaBiglietto(Tbiglietto* x);
void inserisciBiglietto(Tbiglietteria * b, Tbiglietto x);
Tn_mezzo cercaMezzo(Tbiglietteria b);
void salvaBiglietti(Tbiglietteria *b,Tmezzo m);

#endif // __DATI__
