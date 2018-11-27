#include <cstdlib>
#include <iostream>
#include "lista.h"
#include "lista.cpp"
using namespace std;

int main(int argc, char *argv[]){
    Dato d;  //oppure Tdato d;
	/*Nodoptr lista1 = NULL;

	//d = Dato(1, 1.3); //oppure Tdato(1, 1.3);
	//d.stampa();       //test di stampa di Tdato

	lista1 = new Nodo();     //lista che contiene 1 nodo di default
    d.index = 2;  d.value = 10.4;
	lista1= insert_first(lista1,d);
    //stampa(lista1);
    d.index = 2;  d.value = 10.0;
    lista1= insert_first(lista1,d);
    //stampa(lista1);
    d.index = 2;  d.value = 14;
    lista1= insert_first(lista1,d);
    stampa(lista1);
    printf("\n\n");
    printf("%d",lung(lista1));
    //d.index = 3;  d.value = -1.5;
//	x = insert_first(x,d);
    //stampa(x);
    /*d.index = 4;  d.value = 0.0;
	x = insert_last(x,d);
    stampa(x);
    */
    /*d.index = 5;  d.value = 3.0;
	lista1 = insert_last(lista1,d);
    stampa(lista1);
    printf("\n\n");

    Nodoptr lista2=NULL;
    lista2=insert_last(lista2,d);

    printf("\n\n");
    stampa(lista2);

    printf("\n\n");
    lista1=remove_first(lista1);
    stampa(lista1);

    printf("\n\n");
    lista1=remove_last(lista1);
    stampa(lista1);

    printf("\n\n");
    lista1=remove_last(lista1);
    stampa(lista1);
    /*
    cout << "numero elementi in lista:" << x.lung() << endl;
    x = remove_first(x);
    stampa(x);
    x = remove_last(x);
    stampa(x);
    x = search_remove(x,4);
    stampa(x);
	*/


	/*Nodoptr arrayliste[3];
	arrayliste[0] = NULL;
	arrayliste[1] = NULL;
	arrayliste[2] = NULL;
    */
    Nodoptr listaordinata=NULL;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 3.1;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 6.1;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 2.9;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 2.8;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 2.5;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    d.index = 5;  d.value = 3.5;
    listaordinata=insert_order(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");


    d.index = 5;  d.value = 2.5;
    listaordinata=remove_select(listaordinata,d);
    stampa(listaordinata);
    printf("\n\n");

    return 0;
    //system("PAUSE");    return EXIT_SUCCESS;
}
