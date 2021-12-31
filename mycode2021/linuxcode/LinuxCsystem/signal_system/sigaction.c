#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void sig_catch(int signo){ //回调函数，内核是调用者
    if(signo == SIGINT){
    printf("catch you SIGINT! %d \n",signo);
    sleep(10);
    }else if(signo == SIGQUIT){
    printf("catch you SIGQUIT! %d \n",signo);
    }
}
void sys_err(char *str){
    perror(str);
    exit(1);
}
int main(int argc,char *argv[]){
    struct sigaction act,oldact;
    act.sa_handler = sig_catch; //设置回调函数
    sigemptyset(&(act.sa_mask)); //清空sa_mask屏蔽字(只在sig_catch工作时有效)
    act.sa_flags = 0; //默认处理动作
    sigaddset(&act.sa_mask,SIGQUIT);

    int ret1 = sigaction(SIGINT,&act,&oldact);
    if(ret1 == -1){
        perror("sigaction error");
    }

    //int ret2 = sigaction(SIGQUIT,&act,&oldact);
    //if(ret2 == -1){
        //perror("sigaction error");
    //}
    while(1);
    return 0;
}