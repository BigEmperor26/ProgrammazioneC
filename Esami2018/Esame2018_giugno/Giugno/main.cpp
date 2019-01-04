#include <iostream>
#include <cstdlib>
#include <cstring>
#include "dati.h"
using namespace std;

int main()
{

    TcodaFIFO* p[3] = {NULL,NULL,NULL};
    Tspedizione s;
    for(int i=0;i<5;i++){
        creaSpedizione(&s);
        addPacco(p,s);
    }
    stampaSpedizioni(p,3);
    delPacchi(p,ORDINARIO,3);

    stampaSpedizioni(p,3);


    return 0;
}
