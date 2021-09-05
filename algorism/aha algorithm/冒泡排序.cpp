//时间复杂度 o(n*n)
#include<stdio.h>
#include<stdlib.h>
struct student{
    int score;//将分数和名字进行绑定
    char name[20];
};
int main()
{
    struct student a[100],t;
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%s %d",a[i].name,&a[i].score);
    for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++)
    {
        if(a[j].score<a[j+1].score)
        {t=a[j];a[j]=a[j+1];a[j+1]=t;}
    }
    for(i=0;i<n;i++)
    printf("%s\n",a[i].name);
    system("pause");
}