#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int pipefd[2],ret;
    pid_t pid;
    ret = pipe(pipefd);
    if(ret == -1){
        sys_err("pipe error");
    }
    pid = fork();
    if(pid == -1){
        sys_err("fork error");
    }else if(pid == 0){
        close(pipefd[0]);
        dup2(pipefd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);
        sys_err("execlp ls error");
        close(pipefd[1]);
    }else if(pid > 0){
        close(pipefd[1]);
        dup2(pipefd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);
        sys_err("execlp wc error");
        close(pipefd[0]);
    }
    return 0;
}