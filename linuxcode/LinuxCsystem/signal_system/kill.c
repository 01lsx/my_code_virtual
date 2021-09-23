#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(int argc,char *argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
    sleep(5);
    printf("this is child,pid = %d,ppid = %d\n",getpid(),getppid());
    int ret = kill(getppid(),SIGKILL);
        if(ret == -1){
            perror("kill error");
            exit(1);
        } 
        printf("删除进程组成功！\n");
    }else if(pid > 0){
        while(1){
        printf("this is parent,childpid = %d,pid = %d\n",pid,getpid());
        sleep(1);
        //printf("已杀死子进程\n");
        }
    }
    return 0;
}