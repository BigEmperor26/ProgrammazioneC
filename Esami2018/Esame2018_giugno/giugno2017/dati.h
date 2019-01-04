#ifndef __DATI__
#define __DATI__
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAX 20
#define N 3
typedef enum Talimentazione{ BENZINA, DIESEL, GPL}Talimentazione;

typedef struct Tdata{
    unsigned int gg;
    unsigned int mm;
    unsigned int aa;
    Tdata (){
        gg=mm=aa=0;
    }
    Tdata (unsigned int _gg,unsigned int _mm,unsigned int _aa){
        gg = _gg; mm = _mm; aa = _aa;
    }
    void stampa(){
        printf("%u/%u/%u",gg,mm,aa);
    }
}Tdata;

typedef struct Tparcheggio{
    Tdata dataParcheggio;
    char nomeCliente[MAX];
    Talimentazione alimentazioneAuto;
    float importo;
    Tparcheggio(){
        importo=0;
    }
    void stampa(){
        dataParcheggio.stampa();
        printf(" %s ",nomeCliente);
        switch(alimentazioneAuto){
            case 0: printf("(BENZINA)"); break;
            case 1: printf("(DIESEL)"); break;
            case 2: printf("(GPL)"); break;
        }
        printf(" %f",importo);
    }
}Tparcheggio;
typedef struct Tnodo{
    Tparcheggio data;
    Tnodo* next;
    Tnodo* prev;
    Tnodo(){
        prev=next=NULL;
    }
    Tnodo(Tparcheggio d,Tnodo* _prev,Tnodo* _next){
        data = d;
        prev=_prev; next=_next;
    }
    void stampa(){
        data.stampa();
        printf("\t");
    }
}Tnodo;

typedef struct Tincasso{
    float incasso;
    int n;
    Tincasso(float _incasso, int _n){
        n =  _n; incasso = _incasso;
    }
}Tincasso;
void creaParcheggio(Tparcheggio* p);
void addParcheggio(Tnodo* s[], Tparcheggio p);
Tnodo* insertLast(Tnodo* s,Tparcheggio p);
Tincasso incassoParcheggio(Tnodo* s);
Tnodo* removeFirst(Tnodo* s);
Tparcheggio readFirst(Tnodo* s);
void stampaLista(Tnodo* s);
#endif // __DATI__
