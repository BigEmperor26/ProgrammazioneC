#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
    int a[5][5];
    int m=5; int n=5;
    for(int h=0;h<m;h++){
        a[h][0]=h+1;
        int i=0; int j=0; bool index=true;
        for(int k=1;k<n;k++){
            a[h][k]=a[h][i]+a[h][j];
            if(index){
                i++; index=!index;
            }else{
                j++; index=!index;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
