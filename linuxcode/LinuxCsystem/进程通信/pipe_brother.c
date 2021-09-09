#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int pipefd[2];
    int ret,i;
    pid_t pid;
    ret = pipe(pipefd);
    if(ret == -1){
        sys_err("pipe error");
    }
    for(i=0;i<2;i++){
        pid = fork();
        if(pid == -1){
            sys_err("fork error");
        }if(pid == 0){
            break;
        }
    }
    if(i == 0){ //兄进程
        close(pipefd[0]);
        dup2(pipefd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);
        sys_err("execlp ls error");
        close(pipefd[1]);
    }else if(i == 1){  //弟进程
        close(pipefd[1]);
        dup2(pipefd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);
        sys_err("execlp wc error");
        close(pipefd[0]);
    }else if(i == 2){
        close(pipefd[0]);
        close(pipefd[1]);
        wait(NULL);
        wait(NULL);
    }
    return 0;
}