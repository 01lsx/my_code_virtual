#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
void myfunc(int signo)
{
    printf("hello world!");
}
int main(void){
    struct itimerval it,oldit;
    signal(SIGALRM,myfunc);
    it.it_interval.tv_sec = 5;
    it.it_interval.tv_usec = 0;
    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;

    if(setitimer(ITIMER_REAL,&it,&oldit) == -1){
        perror("setitimer error");
        return -1;
    }
    return 0;
}