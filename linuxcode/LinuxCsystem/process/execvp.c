#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
    }else if(pid == 0){
        char *argv[] = {"ls","-l","-h",NULL};
        execvp("ls",argv);
        perror("exec error");
        exit(1);
    }else if(pid > 0){
        sleep(1);
        printf("i`m parent,pid = %d",pid);
    }
    return 0;
}