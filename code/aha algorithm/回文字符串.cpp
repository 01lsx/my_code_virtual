#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char a[101],s[101];
    int i,len,mid,next,top;
    top=0;
    scanf("%s",a);
    len=strlen(a);
    mid=len/2-1;
    
    for(i=0;i<=mid;i++)
    {
        s[++top]=a[i];
    }
    
    if(len%2==0)
    next=mid+1;
    else
    next=mid+2;
    
    for(i=next;i<len;i++)
    {
        if(s[top]!=a[i])
        break;
        top--;
    }
    if(top==0)
    printf("YES");
    else
    printf("NO");


    getchar();getchar();
    return 0;
}