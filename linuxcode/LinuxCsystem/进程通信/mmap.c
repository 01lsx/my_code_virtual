#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    int fd = open("mmapfile",O_RDWR|O_CREAT|O_TRUNC,664);
    if(fd == -1){
        sys_err("open error");
    }
    /* 
    lseek(fd,10,SEEK_END);
    write(fd,"\0",1);
    */
    int n = ftruncate(fd,20);
    if(n == -1){
        sys_err("ftruncate error");
    }
    int len = lseek(fd,0,SEEK_END);
    if(len == -1){
        sys_err("lseek error");
    }
    char *p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p == MAP_FAILED){
        sys_err("mmap error");
    }
    strcpy(p,"hello mmap");
    printf("%s",p);
    int ret = munmap(NULL,len); //类似malloc函数，mmap建立的映射区在使用结束后也应该调用类似free的函数来释放。
    if(ret == -1){
        sys_err("munmap error");
    }
    return 0;
    close(fd);
}