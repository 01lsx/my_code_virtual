#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[]){
    pid_t pid,wpid;
    int i,status;
    for(i=0;i<5;i++){
        pid = fork();
        if(pid == -1){
            perror("fork error");
            exit(1);
        }else if(pid == 0){
            break;
        }
    }
    if(i == 5){
        while((wpid = waitpid(-1,&status,WNOHANG)) != -1){
            if(wpid == 0){
                sleep(1);
                continue;
            }if(wpid > 0){
                printf("wait child %d \n",wpid);
            }
        }
    }else{
        sleep(i);
        printf("i`m child %dth,pid = %d\n",i+1,getpid());
    }
}