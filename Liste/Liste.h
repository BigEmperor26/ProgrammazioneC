#ifndef __LISTE_H__
#define __LISTE_H__

struct EL {
    int info;
    struct EL *next;
};
typedef struct EL ElemLista;
typedef ElemLista *ListadiInt;//puntatore ad una Lista
typedef enum boolean{false=0,true=1}boolean;
void init();
void stampa(ListadiInt Lista);
void inserisci_coda(ListadiInt *Lista, int elem);
void inserisci_testa(ListadiInt *Lista, int elem);
void inserisci();
void ricerca();
void estrai();
void cancella();
boolean listavuota(ListadiInt *Lista);
#endif // __LISTE_H__
