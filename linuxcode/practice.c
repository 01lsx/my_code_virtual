#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[]){
    pid_t pid,wpid;
    int status;
    pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("---child:i`m going to sleep 5 seconds,pid = %d---\n",getpid());
        sleep(5);
        printf("---child going to die---\n");
        return 66;
    }else if(pid > 0){
        wpid = wait(&status);
        if(wpid == -1){
            perror("wait error");
            exit(1);
        }
        if(WIFEXITED(status)){
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)){
            printf("child killed with signal %d\n",WTERMSIG(status));
        }
        printf("---parent going to die,wpid = %d\n",wpid);
    }
    return 0;
}