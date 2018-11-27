#ifndef __LISTA__
#define __LISTA__
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Tdato{
    int index;
    float value;
    Tdato(){
        index=0;
        value=0.0;
    }
    Tdato(int i,float v){
        index=i;
        value=v;
    }
    ~Tdato(){}
    void stampa(){
        printf("[%d-%f]",index,value);
    }
    bool lt(Tdato cmp){
      return value<cmp.value;
    }
    bool gt(Tdato cmp){
      return value>cmp.value;
    }
    bool equalto(Tdato cmp){
      if(
    }
};

typedef struct Tnodo{
	Tdato dato;
	Tnodo *next;

	Tnodo(){
		dato = Tdato();	next = NULL;
	}
	Tnodo(Tdato _dato){
		dato = _dato;	next = NULL;
	}
	Tnodo(Tdato _dato, Tnodo* _next){
		dato = _dato;	next = _next;
	}
	void stampa(){
		dato.stampa();
	}

};

typedef Tdato Dato;
typedef	Tnodo Nodo;
typedef Tnodo* Nodoptr;

Nodoptr insert_first(Nodoptr s,Dato elem);
void stampa(Nodoptr s);
int lung(Nodoptr s);
Nodoptr insert_last(Nodoptr s,Dato elem);
Nodoptr remove_first(Nodoptr s);
Nodoptr remove_last(Nodoptr s);
Nodoptr remove_select(Nodoptr s,Dato elem);
Nodoptr insert_order(Nodoptr s,Dato elem);

#endif
