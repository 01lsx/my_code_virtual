#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>

struct student{
    int id;
    char name[20];
    int age;
};

void sys_err(const char *str){
    perror(str);
    exit(1);
}

int main(int argc,char *argv[]){
    struct student stu = {1,"xiaoming",18};
    struct student *p;
    int fd = open("mmapfile",O_RDONLY);
    if(fd == -1){
        sys_err("open error");
    }
    //ftruncate(fd,sizeof(stu));
    p = mmap(NULL,sizeof(stu),PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED){
        sys_err("mmap error");
    }
    close(fd);
    while(1){
    printf("student id = %d,name = %s,age = %d\n",p->id,p->name,p->age);
    sleep(1);
    }
    int ret = munmap(p,sizeof(stu));
    if(ret == -1){
        sys_err("munmap error");
    }
    return 0;
}