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
}
```
- contiene tipi di dato. Accesso agli elementi tramite __`.`__ 

##### typedef
```c
typedef TipoDato NuovoTipoDato
```
- NuovoTipoDato diventa una keyword equivalente a TipoDato
- Utilizzo con __`enum`__ `typedef enum{val1,val2};` 
- Utilizzo con __`struct`__ `typedef struct TipoDato{
}TipoDato;`

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

###### casting
###### i++ e ++i
---
### Funzioni
##### Output
###### printf
#### Input
###### scanf
---
*Realizzato da Michele Yin.*