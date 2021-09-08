#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int status;
    pid_t pid,wpid;
    pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("child process going to sleep 5 seconds,child pid = %d\n",getpid());
        sleep(5);
        printf("chile is going to die\n");
    }else if(pid > 0){
        wpid = wait(&status);
        if(wpid == -1){
            perror("wait error");
            exit(1);
        }
        printf("parent is die,child is recycle,pid = %d\n",wpid);
    }
    return 0;
}