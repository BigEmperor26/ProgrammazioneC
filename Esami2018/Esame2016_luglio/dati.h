#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
typedef struct Tpunteggio{
    unsigned int puntiA;
    unsigned int puntiB;
    Tpunteggio{
        puntiA = 0;
        puntiB = 0;
    }
    Tpunteggio{

    }
    void stampa(){
        printf("[%u %u]",puntiA,puntiB);
    }
}Tpunteggio;
