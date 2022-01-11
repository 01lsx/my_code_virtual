#include<stdio.h>
int fib(int n){                                //fibonacci计算函数
        if(n < 2){
        return n == 0 ? 0 : 1;
    }
    return fib(n-1) + fib(n-2);
}
int main(){
    int i;
    int a[40];                                 //迭代
    a[0] = 0; 
    a[1] = 1;   
        for(i = 0;i < 40;i ++){                    //递归
        printf("%d ",fib(i));
    }   
        printf("\n"); 
        printf("%d ",a[1]);
        printf("%d ",a[0]);
        for(i = 2;i < 40;i++){
        a[i] = a[i-1] + a[i-2];
        printf("%d ",a[i]);
    }
}