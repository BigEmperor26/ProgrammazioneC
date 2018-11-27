#include "lista.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Nodoptr insert_first(Nodoptr s,Dato elem){
        Nodoptr tmp= new Nodo();
        tmp->dato=elem;
        tmp->next=s;
        return tmp;
}
void stampa(Nodoptr s){
    Nodoptr tmp=s;
    while(tmp!=NULL){
        (*tmp).stampa();
        tmp=tmp->next;
    }
}

int lung(Nodoptr s){
    Nodoptr tmp=s;
    int count=0;
    while(tmp!=NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}

Nodoptr insert_last(Nodoptr s,Dato elem){
    Nodoptr p=s;
    if(p==NULL){
        Nodoptr tmp=new Nodo();
        tmp->dato=elem;
        tmp->next=NULL;
        return tmp;
    }
    //ramo else
    while(p->next!=NULL){
        p=p->next;
    }
    Nodoptr tmp=new Nodo();
    tmp->dato=elem;
    tmp->next=NULL;
    p->next=tmp;
    return s;
}

Nodoptr remove_first(Nodoptr s){
    if(s==NULL){
        return NULL;
    }
    Nodoptr p=s;
    p=p->next;
    delete s;
    return p;
}
Nodoptr remove_last(Nodoptr s){
    if(s==NULL){
        return NULL;
    }
    if(s->next==NULL){
        delete s;
        return NULL;
    }
    Nodoptr p=s;
    while(p->next->next!=NULL){
        p=p->next;
    }//arriva all'penultimo ultimo non nullo
    delete p->next;
    p->next=NULL;
    return s;
}
/*
Nodoptr remove_select(Nodoptr s,Dato elem){
    Nodoptr p=s;
    if(s==NULL){
        return NULL;
    }
    if(p->dato.gt(elem) || p->dato.lt(elem)){
        delete p;
        return NULL;
    }
    while(p->next->dato.gt(elem) || p->next->dato.lt(elem)){//controllo che elem sia diverso da dato
        p=p->next;
    }//arriva all'elemento prima di elem
    Nodoptr tmp=p;
    tmp=tmp->next;
    p->next=p->next->next;
    delete tmp;
    return s;
}*/

Nodoptr insert_order(Nodoptr s,Dato elem){
    //solo su liste ordinate
    if(s==NULL){//caso base di lista vuota
        //printf("caso base lista nulla \n");
        s=insert_first(s,elem);
        return s;
    }
    if(s->next==NULL){//caso con lista da 1 elemento
        if((s->dato).lt(elem)){
            //printf("caso base lista 1 elem, insert_last \n");
            s=insert_last(s,elem);
            return s;
        }
        //printf("caso base lista 1 elem, insert_first \n");
        s=insert_first(s,elem);
        return s;
    }
    //caso generico
    Nodoptr p=s;
    while((p->next->dato).lt(elem)){
        if(p->next->next==NULL){//due next perché altrimenti p=p->next genera un errore
            s=insert_last(s,elem);
            return s;
        }
        p=p->next;
    }//ultimo indice minore di elem
    Nodoptr tmp=new Nodo;
    tmp->dato=elem;
    tmp->next=p->next;
    p->next=tmp;
    return s;
}

