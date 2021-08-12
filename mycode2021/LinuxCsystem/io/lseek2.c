#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){ 
int fd = open(argv[1],O_RDWR);
    if(fd < 0){
        perror("open error");
        exit(1);
    }
    
int length = lseek(fd,0,SEEK_END);
    printf("file size:%d\n",length);

    close(fd);
    return 0;
}