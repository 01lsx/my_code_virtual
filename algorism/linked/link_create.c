#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int num;
    struct Node *next;
}NODE,*Linklist;
Linklist creat_linklist_head(int argc,char *argv[]){
    int x;
    Linklist head = (Linklist)malloc(sizeof(NODE));
    head->next = NULL;
    NODE *p;
    scanf("%d",&x);
    while(x != -1){
        p = (NODE *)malloc(sizeof(NODE));
        p->next = head ->next;
        head->next = p;
        p->num = x;
        scanf("%d",&x);
    }
    return head;
}
Linklist creat_linklist_tail(){
    Linklist head = (Linklist)malloc(sizeof(NODE));
    head->next = NULL;
    NODE *r,*p;
    r = head;
    int x;
    scanf("%d",&x);
    while(x != -1){
        p = (NODE*)malloc(sizeof(NODE));
        p->num = x;
        r->next = p;
        r = p;
        scanf("%d",&x);
    }
    r->next = NULL;
    return 0;
}