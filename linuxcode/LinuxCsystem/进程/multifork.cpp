#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    int i;
    pid_t pid;
    for(i=0;i<5;i++){
        if(fork()==0)
            break;
    }
        if(i==5){
            sleep(2);
            printf("i`m parent\n");
        }else{
            sleep(i);
            printf("i`m %dth child\n",i+1);
        }
    return 0;
    
}