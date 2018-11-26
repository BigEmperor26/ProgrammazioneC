#include <iostream>

using namespace std;

typedef struct Tstack{
    int n;//elemento stoccato
    struct Tstack* prox;//puntatore al successivo

}Tstack;
typedef Tstack* stackptr;
void init(stackptr* st){
    *st=NULL;
    //oppure
    //st->n=0;
    //st->s=NULL;
}
int stackIsEmpty(stackptr st){
    if(st==NULL) {return 1;}
    else {return 0;}
}

void push(stackptr *st,int elem){
    /*if(stackIsEmpty(st)){
        st=new Tstack;
        st->n=elem;
        st->prox=NULL;
    }else{*/
        stackptr tmp=new Tstack;
        tmp->n=elem;
        tmp->prox=*st;
        *st=tmp;

}

int pop(stackptr *st){
    stackptr tmp= (*st)->prox;
    int data= (*st)->n;
    delete *st;
    *st=tmp;
    return data;
}
void print(stackptr st){
    while(!stackIsEmpty(st)){
        printf("%d ",st->n);
        st=st->prox;
    }
}
int main()
{
    stackptr st;
    init(&st);
    push(&st,1);
    printf("%d\n",pop(&st));
    push(&st,1);
    push(&st,1);
    push(&st,1);
    push(&st,1);
    push(&st,1);
    print(st);
    cout << "Hello world!" << endl;
    return 0;
}
