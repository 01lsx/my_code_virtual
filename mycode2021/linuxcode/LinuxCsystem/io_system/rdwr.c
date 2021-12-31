#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
    char buf[1024];

    int n=0;
    int fd,fd_out;

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        perror("open argv[1]");
        exit(1);
    }
    fd_out = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd == -1){
        perror("open argv[2]");
        exit(1);
    }

    while((n = read(fd,buf,1024)) != 0){
        if(n < 0){
            perror("read error");
            break;
        }
        write(fd_out,buf,n);
    }

    close(fd);
    close(fd_out);
    return 0;
}