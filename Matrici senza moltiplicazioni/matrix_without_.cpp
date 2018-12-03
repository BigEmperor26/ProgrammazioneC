#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a[5][5];// 1
    int m=5; int n=5;//1+1
    for(int h=0;h<m;h++){//1 + m+1 + m
        a[h][0]=h+1;//m
        int i=0; int j=0; bool index=true; //m + m + m
        for(int k=1;k<n;k++){//(1 + n-1+1 + n-1)*m
            a[h][k]=a[h][i]+a[h][j];//(n-1)*m
            if(index){//(n-1)*m
                i++; index=!index;//(n-1 + n-1)*m/2
            }else{
                j++; index=!index;//(n-1 + n-1)*m/2
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
