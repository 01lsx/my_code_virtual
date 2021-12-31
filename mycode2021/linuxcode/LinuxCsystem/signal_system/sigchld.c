#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
void sys_err(char *str){
    perror(str);
    exit(1);
}
void catch_child(int signo){
    pid_t wpid;
    int status;
    // while((wpid = waitpid(-1,&status,0)) != -1){
    //     //if(wpid == -1){ sys_err("wait error");}
    //     printf("------ catch child pid = %d,ret = %d",getpid());
    // }
    while((wpid = wait(NULL)) != -1){
        if(wpid == -1){
            sys_err("wait error");
        }
    printf("recovery the chile pid = %d\n",wpid);
    }
}
int main(int argc,char *argv[]){
    pid_t pid;
    int i = 0;
    for(i = 0;i < 15;i++){
        if((pid = fork()) == 0)
        break;
    }
    if(i == 15){
        struct sigaction act;
        act.sa_handler = catch_child;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sigaction(SIGCHLD,&act,NULL);
        printf("this is parent pid = %d\n",getpid());
        while(1);
    }else{
        sleep(1);
        printf("this is child pid = %d\n",getpid());
    }
    return 0;
}