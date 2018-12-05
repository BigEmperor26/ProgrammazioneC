#include <cstdlib>
#include <iostream>
#include "dati.h"
using namespace std;


int main(){
    TstackLIFO* pozzi[3];
    for(int i=0;i<3;i++){   pozzi[i]= new TstackLIFO(5); }
    Tpozzo p;
    for(int i=0;i<3;i++){  creaPozzo(&p); addPozzo(pozzi,p); }
    stampaPozzi(pozzi);
    while(! pozzi[0]->stackIsEmpty()){
        p = pozzi[0]->pop();
        p.stampa();
    }
    return 0;
}
