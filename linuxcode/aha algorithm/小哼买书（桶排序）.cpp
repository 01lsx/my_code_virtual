#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[1001],t,i;
    int n;
    scanf("%d",&n);
    for(i=0;i<1000;i++)
    a[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    for(i=0;i<1000;i++)
    {
        if(a[i]==1)
        printf("%d ",i);
    }
system("pause");
}