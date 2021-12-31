#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,int argv[]){
    int fd;
    fd = open("/home/lsx/work/test.c",O_RDONLY|O_CREAT|O_TRUNC,0644);
    printf("fd = %d,errno = %d:%s\n",fd,errno,strerror(errno));
    close(fd);
    
    return 0;
}
