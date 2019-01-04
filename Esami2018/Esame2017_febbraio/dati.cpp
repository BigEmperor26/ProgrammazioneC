#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "dati.h"
using namespace std;

/*
void creaRiparazione(Triparazione* x){
    x->importo = rand()%(50000 - 8000 + 1) + 8000;
    x->importo /= 100.00;
    scanf("%s",x->nomeCliente);
    bool exit = false;
    do{
        char tmp[MAX];
        scanf("%s",tmp);
        if(strcmp(tmp,"MOTORE")){   x->lavoro = MOTORE; exit = true;}
        if(strcmp(tmp,"CARROZZERIA")){   x->lavoro = CARROZZERIA; exit = true;}
        if(strcmp(tmp,"VETRI")){   x->lavoro = VETRI; exit = true;}
    }while(!exit);
    x->dataRiparazione = Tdata(rand()%32+1,rand()%13+1,rand()%3 + 2017);
}
*/
void creaRiparazione(Triparazione* x){
    x->importo = rand()%(50000 - 8000 + 1) + 8000;
    x->importo /= 100.00;
    x->nomeCliente[0] = '\0';
    bool exit = false;
    x->lavoro = Tlavoro(rand()%3);
    x->dataRiparazione = Tdata(rand()%32+1,rand()%13+1,rand()%3 + 2017);
}
void addRiparazione(Tstack* t, Triparazione x){
    if(t==NULL){
        t = new Tstack();
        (t)->s[(t)->n] = x;
    }
    else{
        if(!(t)->isFull()){
            (t)->push(x);
        }else{
            FILE* fp =fopen("errori.txt","a");
            fprintf(fp,"[%d/%d/%d] %s %f\n",x.dataRiparazione.gg,x.dataRiparazione.mm,x.dataRiparazione.aa,x.nomeCliente,x.importo);
        }
    }
}

Triparazione selectRiparazione(Tstack t[], int n){
    Triparazione max_import;
    for(int i=0;i<n;i++){
        Triparazione tmp = t[i].pop();
        if(tmp.importo <= max_import.importo){
            max_import = tmp;
        }
        t[i].push(tmp);
    }
}

Tcassa incassoEFiltro(Tstack t[],int n,Tlavoro lav){
    Tcassa dato(20);
    Triparazione tmp;
    for(int i=0;i<n;i++){
        while(!t[i].isEmpty()){
            tmp = t[i].pop();
            dato.insieme.push(tmp);
            dato.somma += tmp.importo;
        }
    }
    return dato;
}

