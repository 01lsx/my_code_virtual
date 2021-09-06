#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        while(1){
            sleep(1);
            printf("i`m child process parent-pid = %d\n",getppid());
        }
    }else if(pid > 0){
            printf("i`m parent process pid = %d\n",pid);
            sleep(8);
            printf("----parent going to die ----\n");
    }
    return 0;
}