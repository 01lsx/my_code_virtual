#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

int main(void){
    char buf[10];
    int n,fd;
    
    fd = open("/dev/tty",O_RDONLY|O_NONBLOCK);
    if(fd < 0){
        perror("open /dev/tty");
        exit(1);
    }

tryagain:
    n = read(fd,buf,10);
    if(n<0){
        if(errno != EAGAIN){
            perror("read error");
            exit(1);
        }else{
            write(STDOUT_FILENO,"try again\n",strlen("try again\n"));
            sleep(2);
            goto tryagain;
        }
    }
    write(STDOUT_FILENO,buf,n);
    close(fd);

    return 0;
}