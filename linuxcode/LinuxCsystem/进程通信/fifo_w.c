#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int fd;
    char buf[1024];
    fd = open(argv[1],O_WRONLY);
    if(fd == -1){
        sys_err("open error");
    }
    int i = 0;
    while(1){
        sprintf(buf,"hello &d\n",i++);
        write(fd,buf,strlen(buf));
        sleep(1);
    }
    close(fd);
    return 0;
}