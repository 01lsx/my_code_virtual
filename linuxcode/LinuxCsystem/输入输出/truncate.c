#include<unistd.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    //open/lseek(fd,249,SEEK_END)/write(fd,"a",1);
    int ret = truncate(argv[1],250);

    printf("ret = %d\n",ret);
    return 0;
}