#ifndef __DATI__
#define ___DATI__
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 20
using namespace std;

typedef enum Tlavoro{ MOTORE, CARROZZERIA, VETRI}Tlavoro;

typedef struct Tdata{
    unsigned int gg;
    unsigned int mm;
    unsigned int aa;
    Tdata(){
        aa=gg=mm=0;
    }
    Tdata(unsigned int _gg,unsigned int _mm,unsigned int _aa){
        gg = _gg;
        mm = _mm;
        aa = _aa;
    }
    void stampa(){
        printf("%u/%u/%u",gg,mm,aa);
    }
}Tdata;

typedef struct Triparazione {
    Tdata dataRiparazione;
    char nomeCliente[MAX];
    float importo;
    Tlavoro lavoro;
    Triparazione(){
        nomeCliente[0] = '\0';
        importo = 0.0;
    }
    void stampa(){
        dataRiparazione.stampa();
        printf(" %s %f",nomeCliente,importo);
    }
}Triparazione;

typedef struct Tstack {
    int n;
    //Tbiglietto;
    int dim;
    Triparazione* s;
    Tstack(){
        n = 0;
        dim = 5;
        s = new Triparazione[5];
    }
    Tstack(int _dim){
        n = 0;
        dim = _dim;
        s = new Triparazione[dim];
    }
    void push(Triparazione dato){
        s[n] = dato;
        n++;
    }
    Triparazione pop(){
        n--;
        return s[n+1];
    }
    bool isEmpty(){
        return n==0;
    }

    bool isFull(){
        return n==dim;
    }
    void stampa(){
        for(int i=0; i<n;i++){
            printf("\t");
            s[i].stampa();
        }
    }
}Tstack;

typedef struct Tcassa{
    float somma;
    Tstack insieme;
    Tcassa(){
        somma=0;
    }
    Tcassa(int d){
        somma=0;
        insieme = Tstack(d);
    }
    void stampa(){
        printf("%f",somma);
        insieme.stampa();
    }
}Tcassa;

typedef Tstack* Tstackptr;
void creaRiparazione(Triparazione* x);
void addRiparazione(Tstack* t, Triparazione x);
Triparazione selectRiparazione(Tstack t[], int n);
Tcassa incassoEFiltro(Tstack t[],int n,Tlavoro lav);

#endif // __DATI__
