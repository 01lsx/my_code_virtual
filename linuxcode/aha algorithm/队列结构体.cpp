#include<stdio.h>
#include<stdlib.h>
struct queue{
    int num[100];
    int head;
    int tail;
};
int main(){
    int i;
    struct queue q;
    q.head=1;
    q.tail=1;
    for(i=1;i<=9;i++){
    scanf("%d",&q.num[q.tail]);
    q.tail++;
    }
    while(q.head<q.tail)
    {
        printf("%d ",q.num[q.head]);
        q.head++;

    q.num[q.tail]=q.num[q.head];
        q.tail++;
        q.head++;
    }
    getchar();getchar();
    return 0;
}