#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        sleep(5);
        printf("child going to die\n");
    }else if(pid > 0){
        while(1){
            printf("i`m parent,pid = %d\n",pid);
            sleep(1);
        }
    }
    return 0;
}