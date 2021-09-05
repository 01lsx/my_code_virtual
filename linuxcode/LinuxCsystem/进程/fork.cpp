#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
 
int main(int argc,char *argv[]){
    printf("before fork-1-");
    printf("before fork-2-");
    printf("before fork-3-");
    printf("before fork-4-");

    pid_t pid = fork();
    if(pid == -1){
        perror("fork error");
    }else if(pid == 0){
        printf("---clild is created\n");
    }else if(pid > 0){
        printf("parent process: my child is %d\n",pid);
    }
    printf("==============end of file");

    return 0;
}