#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>

typedef struct student{
    int id;
    char name[20];
}STU,*people;

void sys_err(const char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    STU stu = {1,"xiaoming"};
    int fd = open("mmapfile",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        sys_err("open error");
    }
    ftruncate(fd,sizeof(stu));
   /* int len = lseek(fd,0,SEEK_END);
    if(len == -1){
        sys_err("lseek error");
    }
    */
    people p = mmap(NULL,sizeof(stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p == MAP_FAILED){
        sys_err("mmap error");
    }
    close(fd);
    while(1){
    memcpy(p,&stu,sizeof(stu));
    stu.id++;
    sleep(1);
    }
    int q = munmap(p,sizeof(stu));
    if(q == -1){
        sys_err("munmap error");
    }
    return 0;
}