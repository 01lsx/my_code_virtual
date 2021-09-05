#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
    int fd = open("./ps",O_WRONLY|O_TRUNC|O_CREAT,0644);
    if(fd < 0){
        perror("open error");
        exit(1);
    }
    dup2(fd,STDOUT_FILENO);
    
    execlp("ps","ps","aux",NULL);
    perror("exec error");
    
    return 0;
    //这里没有close(fd)，因为后面的代码不会执行，这里靠操作系统的隐式回收机制。
}