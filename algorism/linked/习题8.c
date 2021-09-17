#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
  int data;
  struct node *next;  
}Lnode,*Linklist;

int create_linklist(Linklist *head){
    
    Lnode *newnode,*point;
    int i=1,x=0,length=0;
    printf("please input the %dth node`s data：",i);
    scanf("%d",&x);
    while(x != -1){
        newnode = (Lnode*)malloc(sizeof(Linklist));
        newnode->data = x;
        if(*head == NULL){
            *head = point = newnode;
        }else{
            point->next = newnode;
            point = newnode;
        }
        i++;length ++;
        printf("please input the %dth node`s data：",i);
        scanf("%d",&x);
    }
    return length;
}

int main(){
    int length,i,j;
    Linklist La,Lb,temp;
    printf("if data = -1,exit...\n");
    printf("creating La:\n");   
    int lengtha = create_linklist(&La);
    printf("create La over,length is %d\n",lengtha);
    sleep(2);
    system("reset");
    printf("creating Lb:\n");
    int lengthb = create_linklist(&Lb);
    printf("create Lb over,length is %d\n",lengthb); 
    sleep(2);
    system("reset");

    printf("the linklist La`s length is %d\n",lengtha);
    printf("the linklist Lb`s length is %d\n\n",lengthb);
    
    printf("请输入要操作的起始结点和操作长度：\n");
    printf("i = ");
    scanf("%d",&i);
    printf("length = ");
    scanf("%d",&length);

    if((i+length)>lengtha){
        printf("La is not long enough\n");
    }
    return 0;
}