#ifndef __DATI__
#define __DATI__

typedef enum Tpacco{ORDINARIO,CELERE,PRIORITY}Tpacco;

typedef struct Tspedizione{
    char destinatario[20];
    bool assicurato;
    float peso;
    Tpacco tipoPacco;
    Tspedizione(){
        destinatario[0]='\0';
        peso=-1.00;
    }
    void stampa(){
    printf("%s ",destinatario);
    printf("PESO=%f ",peso);
    printf("PACCO= ");
    switch (tipoPacco){
        case 0 : printf("ORDINARIO\n"); break;
        case 1 : printf("CELERE\n"); break;
        case 2 : printf("PRIORITY\n"); break;
    }
    }
}Tspedizione;

typedef struct TcodaFIFO{
    Tspedizione dato;
    TcodaFIFO* next;
    TcodaFIFO(){
        next=NULL;
    }
    TcodaFIFO(Tspedizione d){
        dato=d;
        next=NULL;
    }
    TcodaFIFO(TcodaFIFO* n,Tspedizione d){
        dato=d;
        next=n;
    }
    void stampa(){
        dato.stampa();
    }
}TcodaFIFO;
void creaSpedizione(Tspedizione* s);
void addPacco(TcodaFIFO* p[],Tspedizione s);
void stampaSpedizioni_(TcodaFIFO *p);
void stampaSpedizioni(TcodaFIFO *p[], int n);
void delPacchi_(TcodaFIFO** p,Tpacco tp);
TcodaFIFO* delPacchi(TcodaFIFO* p[],Tpacco tp, int n);
#endif // __DATI__
