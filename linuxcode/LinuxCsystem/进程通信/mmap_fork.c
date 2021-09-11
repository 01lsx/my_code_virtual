#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
void sys_err(const char *str){
    perror(str);
    exit(1);
}
int number = 100;
int main(int argc,char *argv[]){
    int fd = open("temp",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        sys_err("open error");
    }
    //unlink("temp");
    int ret = ftruncate(fd,1);
    if(ret == -1){
        sys_err("ftruncate error");
    }
    int len = lseek(fd,0,SEEK_END);
    
    int *p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    
    //匿名映射，不需要创建临时文件，省去open unlink close步骤，但是仅限血缘关系间进程通信
    //int *p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
    
    //MAP_ANONYMOUS和MAP_ANON宏只在LINUX环境下，在其他类UNIX系统中可以用/dev/zero来实现匿名。
    //open("/dev/zero",O_RDWR);
    //int *p = mmap(NULL,XXX,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    
    if(p == MAP_FAILED){
        sys_err("mmap error");
    }
    close(fd);
    pid_t pid = fork();
    if(pid == -1){
        sys_err("fork error");
    }else if(pid == 0){
        *p = 4000;
        number = 1000;
        printf("write is over\n");
        printf("information is %d,number is %d\n",*p,number);
    }else if(pid > 0){
        sleep(1);
        printf("read is begining\n");
        printf("information is %d,number is %d\n",*p,number);
    }
    return 0;
}