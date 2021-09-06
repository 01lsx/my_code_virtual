#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,char *argv[]){
    pid_t pid,wpid;
    int status;
    
    pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("---child :going to sleep five seconds,pid = %d\n",getpid());
        sleep(5);
        printf("---child is going to die");
    }else if(pid > 0){
        wpid = wait(&status);
        if(wpid == -1){
            perror("wait error");
            exit(1);
        }
        printf("parent is die");
    }
    return 0;
}