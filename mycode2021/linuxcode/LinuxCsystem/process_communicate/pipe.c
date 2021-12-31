#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int fd[2],i,ret;
    pid_t pid;
    char *str = "hello pipe\n",buf[1024];
    i = pipe(fd);
    if(i == -1){
        sys_err("pipe error");
    }
    pid = fork();
    if(pid == -1){
        sys_err("fork error");
    }else if(pid == 0){
        close(fd[1]);
        ret = read(fd[0],buf,1024);
        write(STDOUT_FILENO,buf,ret);
        close(fd[0]);
    }else if(pid > 0){
        close(fd[0]);
        write(fd[1],str,strlen(str));
        sleep(1);
        close(fd[1]);
    }
    return 0;
}