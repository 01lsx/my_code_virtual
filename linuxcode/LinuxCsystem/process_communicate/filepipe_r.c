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
    char buf[1024];
    char *str = "---user get information---\n";
    fd = open("test.txt",O_RDWR);
    sleep(2); //这里等待filepipe2写入，避免在写入之前读文件内容。
    ret = read(fd,buf,1024);
    if(ret == -1){
        sys_err("read error");
    }
    write(STDOUT_FILENO,buf,ret);
    write(fd,str,strlen(str));//filepipe1向文件中写入一些数据
    close(fd);
    return 0;
}