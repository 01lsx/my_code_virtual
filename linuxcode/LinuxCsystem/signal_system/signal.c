#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void sig_catch(int signo){
    printf("catch you! %d \n",signo);
}
int main(int argc,char *argv[]){
    signal(SIGINT,sig_catch);
    while(1);
    return 0;
}