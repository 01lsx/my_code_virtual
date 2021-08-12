#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MSG_TRY "try again\n"
#define MSG_TIME "time out\n"

int main(void){
    
    int n,i;
    int fd;
    char buf[10];
    
    fd = open("/dev/tty",O_RDONLY|O_NONBLOCK);
    if(fd < 0){
        perror("oepn /dev/tty");
        exit(1);
    }
    printf("open /dev/tyy ok... %d",fd);

    for(i=0;i<5;i++){
        n = read(fd,buf,10);
        if(n > 0){
            break;
        }
        if(errno != EAGAIN){
            perror("read error");
            exit(1);
        }else{
            write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));
            sleep(2);
        }
    }

    if(i == 5){
        write(STDOUT_FILENO,MSG_TIME,strlen(MSG_TIME));
    }else{
        write(STDOUT_FILENO,buf,n);
    }

    close(fd);
    return 0;
}