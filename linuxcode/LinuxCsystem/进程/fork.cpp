#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
 
int main(int argc,char *argv[]){
    printf("before fork-1-\n");
    printf("before fork-2-\n");
    printf("before fork-3-\n");
    printf("before fork-4-\n");

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
    }else if(pid == 0){
        printf("child is created\nchild process: \npid = %d\nparent-pid = %d\n",getpid(),getppid());
    }else if(pid > 0){
        printf("parent process: \nmy child is %d\nmy pid = %d\nmy parent-pid = %d\n",pid,getpid(),getppid());
    }
    printf("==============end of file\n");

    return 0;
}