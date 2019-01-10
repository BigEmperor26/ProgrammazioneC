#include <iostream>
#include <cstdlib>
using namespace std;

typedef enum Tsistoper{WIN, MAC, LINUX}Tsistoper;
typedef char Stringa[20];
typedef struct Tserver{
    Stringa hostname;
    int numCPU, ram;
    Tsistoper so;
    void stampa(){
        printf("%s %d %d ",hostname,numCPU,ram);
        switch (so){
            case 0: printf("WIN\n"); break;
            case 1: printf("MAC\n"); break;
            case 2: printf("LINUX\n"); break;
        }
    }
}Tserver;
typedef struct Tcloud{//elemento base di una lista LIFO
    Tserver server;
    Tcloud *next, *prev;
    void stampa(){
        server.stampa();
    }
}Tcloud;

void creaServer(Tserver* s){
    s->so=Tsistoper(rand()%3);
    s->numCPU=rand()%(8-4+1)+4;
    do{
            scanf("%d",&(s->ram));
    }while(s->ram<4 || s->ram>16);
    scanf("%s",s->hostname);
}

Tcloud* inserisciServer(Tcloud* pc,Tserver s){
    Tcloud* tmp=pc;
    if(tmp==NULL){
            tmp=new Tcloud();
            tmp->server=s;
            tmp->next=NULL; tmp->prev=NULL;
            return tmp;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=new Tcloud();
    tmp->next->server=s;
    tmp->next->next=NULL;
    tmp->next->prev=tmp;
    return pc;
}
void stampaCloud(Tcloud * pc){
    Tcloud* tmp=pc;
    while(tmp!=NULL){
        tmp->stampa();
        tmp=tmp->next;
    }
}
int salvaServer(Tcloud* pc){
    Tcloud* tmp=pc;
    while(tmp!=NULL){
        if(tmp->server.ram>8 && tmp->server.numCPU==8){
            FILE* fp=fopen("server.txt","w");
            if(fp==NULL){ return 0;}
            fprintf(fp,"%s::",tmp->server.hostname);
            switch (tmp->server.so){
                case 0: fprintf(fp,"WIN"); break;
                case 1: fprintf(fp,"MAC"); break;
                case 2: fprintf(fp,"LINUX"); break;
            }
            fprintf(fp," CPU=%d",tmp->server.numCPU);
            fprintf(fp," RAM=%d\n",tmp->server.ram);
        }
        tmp=tmp->next;
    }
    return 1;
}
Tcloud* delServer(Tcloud* pc,Tsistoper sis){
    Tcloud* tmp = pc;
    if(tmp==NULL){
        return NULL;
    }
    while(tmp!=NULL){
        if(tmp->server.so==sis){
            if(tmp==pc){
        		pc=tmp->next;
			}
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            Tcloud* cache=tmp->next;
            delete tmp;
            tmp=cache;
            continue;
        }
        tmp=tmp->next;
    }
    return pc;
}
int main()
{
    //main 1
    Tserver s1;
    creaServer(&s1);
    Tserver s2;
    creaServer(&s2);
    Tserver s3;
    creaServer(&s3);
    Tserver s4;
    creaServer(&s4);

    //main 2
    Tcloud* pc=NULL;
    pc=inserisciServer(pc,s1);
    pc=inserisciServer(pc,s2);
    pc=inserisciServer(pc,s3);
    pc=inserisciServer(pc,s4);

    pc=inserisciServer(pc,s1);
    pc=inserisciServer(pc,s2);
    pc=inserisciServer(pc,s3);
    pc=inserisciServer(pc,s4);
    stampaCloud(pc);


    //main 3
    pc->server.ram=12;
    pc->server.numCPU=8;
    salvaServer(pc);
    //main 4
    cout<<endl;
    pc=delServer(pc,Tsistoper(1));
    stampaCloud(pc);

    return 0;
}
