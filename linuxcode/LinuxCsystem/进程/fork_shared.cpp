#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int var=100;
int main(int argc,char *argv[]){
    pid_t pid;
    pid = fork();
    if(pid == -1){
        perror("fork error");
    }else if(pid == 0){
        //var = 200;
        printf("i`m child\nvar=%d\npid=%d\nparent-pid=%d\n",var,getpid(),getppid());
    }else if(pid > 0){
        sleep(1);
        var = 288;
        printf("i`m parent\nvar=%d\npid=%d\nparent-pid=%d\n",var,getpid(),getppid());
    }
    return 0;
}