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
        printf("---child :going to sleep five seconds,pid = %d---\n",getpid());
        sleep(5);
        printf("---child is going to die---\n");
        return 66;
    }else if(pid > 0){
        //wpid = wait(NULL); //不关注子进程结束原因
        wpid = wait(&status); //如果子进程未终止，父进程阻塞在这个函数上
        if(wpid == -1){
            perror("wait error");
            exit(1);
        }
        if(WIFEXITED(status)){ //为真，说明子进程正常终止
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)){//为真，说明子进程被信号终止
            printf("child kill with signal %d\n",WTERMSIG(status));
        }
        printf("---parent is die,child pid = %d---\n",wpid);
    } 
    return 0;
}