#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    pid_t pid;
    int pipefd[2],i;
    i = pipe(pipefd);
    if(i == -1){
        sys_err("pipe error");
    }
    pid = fork();
    if(pid == -1){
        sys_err("fork error");
    }else if(pid == 0){
        close(pipefd[0]);
        dup2(pipefd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);
        close(pipefd[1]);
        sys_err("execlp ls error");
        
    }else if(pid > 0){
        close(pipefd[1]);
        dup2(pipefd[0],STDIN_FILENO);
        sleep(1);
        execlp("wc","wc","-l",NULL);
        close(pipefd[0]);
        sys_err("execlp wc error");
    }
    return 0;
}