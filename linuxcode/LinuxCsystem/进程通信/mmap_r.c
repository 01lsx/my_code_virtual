#include<stdio.h>
#include<stdlib.h>
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
    STU s = {1,"xiaoming"};
    int fd = open("mmapfile",O_RDONLY);
    if(fd == -1){
        sys_err("open error");
    }
    people p = mmap(NULL,sizeof(s),PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED){
        sys_err("mmap error");
    }
    close(fd);
    while(1){
        printf("student id = %d,name = %s\n",p->id,p->name);
        //printf中的反斜杠很重要，如果不加结果会出现问题
        sleep(1);
    }
    int q = munmap(p,sizeof(s));
    if(q == -1){
        sys_err("munmap error");
    }
    return 0;
}