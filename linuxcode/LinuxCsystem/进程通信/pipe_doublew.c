#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

void sys_err(const char *str){
    perror(str);
    exit(1);
}

int main(int argc,char *argv[]){
    int pipefd[2],ret,i,n;
    char buf[1024];
    pid_t pid;
    ret = pipe(pipefd);
    if(ret == -1){
        sys_err("pipe error");
    }
    for(i=0;i<2;i++){
        pid = fork();
        if(pid == -1){
            sys_err("fork error");
        }else if(pid == 0){
            break;
        }
    }
    if(i == 0){
        close(pipefd[0]);
        write(pipefd[1],"1.hello\n",strlen("1.hello\n"));
    }else if(i == 1){
        close(pipefd[0]);
        write(pipefd[1],"2.world\n",strlen("2.world\n"));
    }else{
        close(pipefd[1]);
        sleep(1);
        n = read(pipefd[0],buf,1024);
        write(STDOUT_FILENO,buf,n);
        for(i=0;i<2;i++){
            wait(NULL);
        }
    }
    return 0;
}