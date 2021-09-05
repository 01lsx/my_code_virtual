#include<stdio.h>
int main()
{
    int a[100],n,i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("%d ",a[0]);
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        printf("%d ",a[i]);
    }
}