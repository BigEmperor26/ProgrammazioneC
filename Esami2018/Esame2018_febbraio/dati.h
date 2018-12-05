#ifndef __DATI__
#define _DATI_
#include <iostream>
#include <cstdlib>
using namespace std;
 typedef enum Ttipo{ AUTO, MOTO, AUTOBUS } Ttipo;
 typedef struct Tveicolo{
     char marca[20];
     int cil;
     float kw;
     Ttipo tipo;
     // metodo stampa
     void stampa(){
        printf("%s ",marca);
        printf("%d ",cil);
        printf("%f ",kw);
        switch(tipo){
            case 0: printf("AUTO\n"); break;
            case 1: printf("MOTO\n"); break;
            case 2: printf("AUTOBUS\n"); break;
        }
     }
}Tveicolo;
typedef struct TcodaFIFO {
    int n, dim, head, tail;
    Tveicolo *s;
    TcodaFIFO (int x) {
        dim = x;
        n = 0;
        head = 0;
        tail = 0;
        s = new Tveicolo [x];
    }
    // metodo stampa
    void stampa(){
        for(int i=0;i<n;i++){
            s[(head+i)%dim].stampa();
        }
    }
} TcodaFIFO;

void creaVeicolo(Tveicolo* v);
void addVeicolo(TcodaFIFO* p,Tveicolo v);
void stampaVeicolo(TcodaFIFO* p);
void delAuto(TcodaFIFO* p,int c);
void write_file(char* nome_file,Tveicolo v);
#endif // __DATI__
