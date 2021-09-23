#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void printset(sigset_t *set);
void system_err(char *str);
int main(int argc,char *argv[]){
    sigset_t set,odset,pding;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigaddset(&set,SIGKILL);
    sigaddset(&set,SIGBUS);
    sigaddset(&set,SIGQUIT);
    int ret1 = sigprocmask(SIG_BLOCK,&set,&odset);
    if(ret1 == -1) system_err("sigprocmask error");
    while(1){
    int ret2 = sigpending(&pding);
    if(ret2 == -1) system_err("sigoending error");
    printset(&pding);
    sleep(1);
    }
}
void printset(sigset_t *set){
    for(int i = 1; i < 32;i++){
        if(sigismember(set,i)){
            putchar('1');
        }else{
            putchar('0');
        }
    }
    printf("\n");
}
void system_err(char *str){
    perror(str);
    exit(1);
}