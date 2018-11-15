#ifndef __LISTE_H__
#define __LISTE_H__

struct EL {
    int info;
    struct EL *next;
};
typedef struct EL ElemLista;
typedef ElemLista *ListadiInt;//puntatore ad una Lista
typedef enum boolean{false=0,true=1}boolean;//definizone di un tipo boolean

void init();
boolean listavuota(ListadiInt Lista);//non è necessario il passaggio per indirizzo
void stampa(ListadiInt Lista);//non è necessario il passaggio per indirizzo
//inserimento ed eliminazione restituiscono 1 se è andato a buon fine, 0 altrimenti ;)
int inserisci_coda(ListadiInt *Lista, int elem);//passato per indirizzo ovviamente
int inserisci_testa(ListadiInt *Lista, int elem);//passato per indirizzo ovviamente
int cancella_testa();
int cancella_coda();

//int inserisci(ListadiInt *Lista,int elem, int posizione); ancora da implementare

//void ricerca();
//void estrai();

#endif // __LISTE_H__
