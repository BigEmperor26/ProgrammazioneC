#include <stdio.h>
#include <stdlib.h>

int main()
{
    //esempio di lettura e scrittura con fprintf e fscanf
    FILE *fp;
    fp=fopen("REPO.txt","w");
    if(fp==NULL){   return 1; }
    fprintf(fp,"%d\n",10);
    fprintf(fp,"%d\n",9);
    fclose(fp);
    fp=fopen("REPO.txt","r");
    if(fp==NULL){   return 1; }
    int prova;
    fscanf(fp,"%d\n",&prova);
    int prova1;
    fscanf(fp,"%d\n",&prova1);
    fclose(fp);
    printf("%d %d",prova,prova1);
    //esempio di conta del numero di elementi di un file
    int n;
    int i=0;
    fp=fopen("REPO.txt","r");
    if(fp==NULL){   return 1; }
    while(fscanf(fp,"%d",&n)==1){ i++;}
    fclose(fp);
    printf("\n\n%d",i);//ci sono due numeri in REPO.txt
    //altro esempio di conta del numero di elementi di un file
    int m;
    int j=0;
    fp=fopen("REPO.txt","r");
    if(fp==NULL){   return 1; }
    while(!feof(fp)){
        fscanf(fp,"%d",&m);
        if(!feof(fp)){ j++;}
    }
    printf("\n\n%d",j);//ci sono due numeri in REPO.txt
    //altro esempio ancora di conta di elementi di un file, con caratteri stavolta
    int o;
    int h=0;
    fp=fopen("REPO.txt","r");
    if(fp==NULL){   return 1; }
    while(!feof(fp)){
        fscanf(fp,"%c",&o);
        if(!feof(fp)){ h++;}
    }
    printf("\n\n%d",h);//in questo caso in REPO.txt sono 5 caratteri '1' '0' '\n' '9' '\n' evita il carattere 'EOF'
    //un altro esempio ancora di conta di elementi su un file
    int p;
    int k=0;
    fp=fopen("REPO.txt","r");
    if(fp==NULL){   return 1; }
    while(fscanf(fp,"%c",&p)==1){ k++;}
    fclose(fp);
    printf("\n\n%d",k);//in questo caso in REPO.txt sono 5 caratteri '1' '0' '\n' '9' '\n' evita il carattere 'EOF'
    return 0;
}
