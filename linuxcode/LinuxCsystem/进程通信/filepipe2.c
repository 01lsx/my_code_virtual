#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int fd,ret;
    char *str = "---success connect---\n";
    char buf[1024];
    fd = open("test.txt",O_RDWR|O_TRUNC|O_CREAT,644);
    write(fd,str,strlen(str));
    sleep(10);

    lseek(fd,0,SEEK_SET);
    ret = read(fd,buf,1024);
    write(STDOUT_FILENO,buf,ret);
    close(fd);
    return 0;
}