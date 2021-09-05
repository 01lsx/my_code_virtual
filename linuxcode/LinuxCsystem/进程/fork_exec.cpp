#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
    }else if(pid == 0){
        execlp("ls","ls","-l",NULL);
        //execl("/bin/ls","ls","-l",NULL);
        perror("exec error");
        exit(1);
    }else if(pid > 0){
        printf("i`m parent pid = %d",pid);
    }
    return 0;
}