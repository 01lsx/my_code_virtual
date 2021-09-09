#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int fd;
    char buf[1024];
    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        sys_err("open error");
    }
    int n;
    while(1){
        n = read(fd,buf,1024);
        write(STDOUT_FILENO,buf,n);
        sleep(3);
    }
    close(fd);
    return 0;
}