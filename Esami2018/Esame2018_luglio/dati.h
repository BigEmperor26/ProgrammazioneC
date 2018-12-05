
#ifndef __DATI__
#define __DATI__
#define MAXDIM 10
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef enum Testrazione {GAS, PETROLIO, ACQUA }Testrazione;
typedef struct Tpozzo{
    char zona[20];
    bool attivo;
    float quantita;
    Testrazione tipoEstrazione;
    Tpozzo(){
        zona[0]='\0';
        attivo=false;
        quantita=-1.0;
    }
    void stampa(){
        printf("%s QTA=%f (",zona,quantita);
        switch(tipoEstrazione){
            case 0 : {printf("GAS"); break;}
            case 1 : {printf("PETROLIO"); break;}
            case 2 : {printf("ACQUA"); break;}
        }
        printf(") attivo=");
        if(attivo){
                printf("SI\n");
        }
        else{
                printf("NO\n");
        }
    }
}Tpozzo;

typedef struct TstackLIFO{
    Tpozzo* s;
    int dim;//dim max
    int N;//indice di elementi presenti
    TstackLIFO(){
        s=NULL;
        dim=MAXDIM;
        N=0;
    }
    TstackLIFO(int _dim){
        s=new Tpozzo[_dim];
        dim=_dim;
        N=0;
    }
    bool stackIsFull(){
        if(N==dim){  return true;}
        else {  return false;}
    }
    bool stackIsEmpty(){
        if(N==0){  return true;}
        else {  return false;}
    }
    void push(Tpozzo p){
        s[N]=p;
        N++;
    }
    Tpozzo pop(){
        Tpozzo tmp=s[N];
        delete (s+N-1);
        N--;
        return tmp;
    }
    void stampa(){
        for(int i=0;i<N;i++){
            (*(s+i)).stampa();
        }
    }
}TstackLIFO;

void creaPozzo(Tpozzo* p){
    p->tipoEstrazione=Testrazione(rand()%3);
    do{
            scanf("%f",&(p->quantita));
    }while(p->quantita<100.00 || p->quantita>800.00);
    p->attivo=bool(rand()%2);
    char tmp[20];
    scanf("%s",tmp);
    strcpy(p->zona,tmp);
}
void addPozzo(TstackLIFO* pozzi[],Tpozzo s){
    int x=rand()%3;
    if(pozzi[x]->stackIsFull()){
        FILE *fp=fopen("noprd.txt","w");
        fprintf(fp,"zona QTA=%d",s.quantita);
        switch(s.tipoEstrazione){
            case 0 : {fprintf(fp,"%s","(GAS)"); break;}
            case 1 : {fprintf(fp,"%s","(PETROLIO)"); break;}
            case 2 : {fprintf(fp,"%s","(ACQUA)"); break;}
        }
    }
    pozzi[x]->push(s);
}
void stampaPozzi(TstackLIFO* pozzi[]){
    for(int i=0;i<3;i++){
        pozzi[i]->stampa();
    }
}
#endif // __DATI__
