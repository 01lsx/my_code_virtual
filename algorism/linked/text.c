#include<stdio.h>
#include<unistd.h>

int main(){
    int a[2],i=0;
    a[0]=1;
    for(i;i<3;i++)
        a[0]++;
    printf("%d\n",a[0]);
}
