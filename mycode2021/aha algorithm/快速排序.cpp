#include<stdio.h>
#include<stdlib.h>
int a[101],n;

void quicksort(int left,int right)
{
    int i,j,t,temp;//t用于交换符合条件的大于小于基准数的两个数
    //temp用来交换i=j的数字与基准数
    if(left>right)
    return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp&&i<j)//i=j的时候停止
        j--;
        while(a[i]<=temp&&i<j)//i=j的时候停止
        i++;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);//使用循环嵌套，将基准数左边的一系列数
    //继续套用快排嵌套
    quicksort(i+1,right);//使用循环签到，将基准书右边的一系列
    //
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(0,n-1);
for(i=0;i<n;i++)
printf("%d ",a[i]);
    system("pause");
}