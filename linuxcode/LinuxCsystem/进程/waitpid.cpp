#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[]){
    pid_t pid,tmpid,wpid;
    int i;
    for(i=0;i<5;i++){
        pid = fork();
        if(pid == 0){
            break;
        }
        if(i == 2){
            tmpid = pid;
            printf("---------pid = %d\n",tmpid);
        }
    }
        if(i == 5){
            printf("i`m parent,before waitpid,pid = %d\n",tmpid);
            //sleep(5);
            //wpid = waitpid(tmpid,NULL,WNOHANG);
            wpid = waitpid(tmpid,NULL,0);
            if(wpid == -1){
                perror("waitpid error");
                exit(1);
            }
            printf("i`m parent,wait a child finish : %d \n",tmpid);
        }else{
            sleep(i);
            printf("i`m %dth child,pid = %d\n",i+1,getpid());
    }
}