#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(void){
    int fd;
    char *p = "test of unlink";
    char *p2 = "after write something";

    fd = open("test.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd < 0){
        perror("open test.txt error");
        exit(1);
    }

    int ret = write(fd,p,strlen(p));
    if(ret == -1){
        perror("write  error");
        exit(1);
    }
    printf("hi!i am printf");
    
    ret = write(fd,p2,strlen(p2));
    if(ret == -1){
        perror("write  error");
        exit(1);
    }
    printf("Enter anykey continue");
    
    getchar();
    
    
    close(fd);
	ret = unlink("test.txt");
	if(ret == -1){
        perror("unlink error");
        exit(1);
    }
    return 0;
}