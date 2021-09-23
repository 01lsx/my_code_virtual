#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>//setitimer函数的头文件
#include<signal.h>
void myfunc(int signo)
{
    printf("hello world!\n");
}
int main(void){
    signal(SIGALRM,myfunc);
    struct itimerval it,oldit;
    it.it_interval.tv_sec = 5;
    it.it_interval.tv_usec = 0;
    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;

    if(setitimer(ITIMER_REAL,&it,&oldit) == -1){
        perror("setitimer error");
        return -1;
    }
    while(1);
    return 0;
}