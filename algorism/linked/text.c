#include<stdio.h>
int main(){
    int n;
    int number[30][30];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0||j == i){
                number[i][j] = 1;
            }else{
                number[i][j] = number[i-1][j-1]+number[i-1][j];
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            if(j != i){
                printf("%d ",number[i][j]);
            }else if(j == i){
                printf("%d\n",number[i][j]);
            }
        }
        
    }
}