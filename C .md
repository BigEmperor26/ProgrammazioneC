# C 
## Note di laboratorio
---
### Strutture di Controllo
##### if
```c
if(condizione){}
```
- opera su condizioni __`int`__ __:__ __`1=true`__ __`0=false`__

##### if else
```c
if(condizione){
}else{}
```
##### else if
```c
if(condizione1){
}else{}if(condizione2){}
```

##### for
```c
for(i=0;i<n;i++){}
```
- non dichiarare **`int i=0`**  all'interno del **`for`**

##### switch
```c
switch(int){
	case a: 
	case b: break;
	default:
}
```
- la variabile deve essere **`int`**, letta come **`char`**
- fall-through le istruzioni vengono eseguite e cascata
- **`break`** rompe il flusso
- __`default`__ è eseguito senza corrispondenza

##### while
```c
while(condizione){}
```
##### do while
```c
do{}while(condizione);
```
- __`do`__ viene eseguito almeno una volta, controllo alla fine

##### break
```c
break;
```
- esce dal blocco di istruzioni corrente. Compatibile con __`switch`__, __`while`__, __`for`__, __`do-while`__

##### continue
```c
continue;
```
- esce dall'iterazione corrente e va direttamente alla prossima. Compatibile con __`while`__, __`for`__, __`do-while`__

##### go to


---

### Variabili 
##### Tipi semplici
__`int`__ __`char`____`float`____`double`__

- non è presente un tipo __`bool`__
- confronto tra numeri in virgola mobile
- opzionali attributi __`long`__ __`const`__

```c
//float a == float b
(a-ε<=b)&&(b<=a+ε)
```
##### enum
```c
enum TipoDato{ val1, val2...};
```
- operazione sintattica. val1 è di tipo __`int `__
- il primo elemento se non è specificato è __`0`__

##### struct
```c
struct{
	int a;
	...
};
```
- contiene tipi di dato. Accesso agli elementi tramite __`.`__ 

##### typedef
```c
typedef TipoDato NuovoTipoDato;
```
- NuovoTipoDato diventa una keyword equivalente a TipoDato
- Utilizzo con __`enum`__ `typedef enum{val1,val2};` 
- Utilizzo con __`struct`__ `typedef struct TipoDato{
}TipoDato;`
```c
typedef TipoDato * PuntatoreTipoDato;
```
- PuntatoreTipoDato è un puntatore a TipoDato
```c
typedef TipoDato ArrayTipoDato[10];
```
- __`[]`__ l'array va a destra. __`ArrayTipoDato`__ è un __`TipoDato[20]`__
##### array
```c
TipoDato Identificatore[];
```
- accesso tramite __`Identificatore[i]`__
- primo elemento è __`0`__ 
- array multidimensionali `TipoDato Identificatore[][]...[];`
- passaggio alle funzioni tramite _indirizzo_

##### stringhe
```c
char stringa[];
```
- array di __`char`__
- ultimo elemento __`'\0'`__
- passaggio alle funzioni tramite _indirizzo_

##### puntatori
```c
TipoDato *puntatore;
```
- variabile che punta ad una cella di memoria
- nel caso di puntatori a __`struct`__ __:__ si usa __`puntatore->elemento`__ invece di __`(*puntatore).elemento`__ 


---
### Operatori 
|operatori | associatività|
|:-------------:|:--------------:|
| () [] -> . |da sinistra a destra|
| ! - ++ -- + - * & (type) sizeof | da destra a sinistra|
| * / % | da sinistra a destra|
| + - | da sinstra a destra|
| << >> | da sinistra a destra|
| < <= > >= | da sinistra a destra|
| == != | da sinistra a destra|
| & | da sinistra a destra|
| ^ | da sinistra a destra|
| \ | da sinistra a destra|
| && | da sinistra a destra|
| \|\| | da sinistra a destra|
| ? : | da destra a sinistra|
| = += -= /= %= \^= \|= <<= >>= | da destra a sinistra|
| ,| da sinistra a destra|

---
### Funzioni
```c
TipoDato nomeFunzione(Tipo parametri,...){
return TipoDato;
};
```
- `return TipoDato;` termina il blocco di istruzioni della funzione
##### FILE
```c
FILE *fp;
fp=fopen("nomefile",modalità);
fclose(fp);
//Header di altre funzioni
int remove(fp);
int rename(nome,nuovonome);
int ferror(FILE *fp);
int fseek(FILE *fp, long int offset, int ref);
int feof(FILE *fp);
```
- **Modalità:** 

|Lettura|Scrittura|Append||
|-----|-------|-----|----|
|r|w|a|Per caratteri|
|rb|wb|ab|Binario|
|r+|w+|a+|Scrittura E Lettura|
|r+b|w+b|a+b|Scrittura E Lettura Binaria|

- non usare +, problemi di gestione dell'indice
 
##### Output
- Output su **FILE**
- **`stdout`** è un **FILE** per il monitor
```c
//STDOUT 
int printf("modalità",dato);
//CARATTERI
int putchar(char c);
```
```c
//FILE
int fprintf(FILE *fp,"modalità",dato);
//CARATTERI
int putc(int c, FILE *fp);
//LETTURA STRINGA
int fputs (const char * str, FILE * stream );
//SCRITTURA BINARIA
int fwrite(void *ptr, dim_elem, n_elem, FILE *fp);
```
#### Input
- Input su **FILE**
- **`stdin`** è un **FILE** per la tastiera
```c
//STDIN
int scanf("modalità",&dato); non è richiesto & per strighe,array e puntatori
//CARATTERI
int getchar();
```
```c
//FILE
int fscanf(FILE *fp,"modalità",&dato);
//CARATTERI
int getc(FILE *fp);
//LETTURA STRINGA
char *fgets(char *s, int length, FILE *fp);
//LETTURA BINARIA
int fread(void *ptr, dim_elem, n_elem, FILE *fp);

```
---
### Strutture dati dinamiche

__Allocazione__
```c
//C
Tipo *ptr = malloc(sizeof(Tipo));
```
```c++
//C++
Tipo *ptr = new Tipo;
```

__De-allocazione__
```c
//C
free (ptr);
```
```c++
//C++
delete ptr = new Tipo;
```
---
#### Liste
```c
//lista ->
struct EL{
    tipoDato info;
    struct EL *prox;
};
typedef EL ElemLista;
typedef ElemLista *ListadiElem;//puntatore ad una lista
```
- __Testa__ e __coda__. La __coda__ __`-> NULL`__
- Accesso sequenziale. Da __Testa__ e __coda__.
- dimensione dinamica
```c
//Lista doppiamente linkata <->
struct EL{
    tipoDato info;
    struct EL *prox;
    struct EL *prec;
};
```
#### Stack
- __LIFO__ Last In First Out
- Implementazione con __Array__ o __Liste__
- costo unitario di __`pop()`__ e __`push()`__

*Realizzato da Michele Yin.*
