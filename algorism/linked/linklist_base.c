//头插法 尾插法
//前插 后插
//正序插 倒序插
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int         data;
    struct Node *next;
}Lnode,*Linklist;

Linklist create_linklist_head(){
    int      x;
    Lnode    *p;
    Linklist head = (Linklist)malloc(sizeof(Lnode));
    head->next = NULL;
    scanf("%d",&x);
    while(x != -1){
        p = (Lnode *)malloc(sizeof(Lnode));
        p->next = head ->next;
        head->next = p;
        p->data = x;
        scanf("%d",&x);
    }
    return head;
}

Linklist create_linklist_tail(){

    Linklist head = (Linklist)malloc(sizeof(Lnode));
    Lnode    *r,*p;
    int      x;
    head->next = NULL;
    r = head;
    scanf("%d",&x);
    while(x != -1){
        p = (Lnode*)malloc(sizeof(Lnode));
        p->data = x;
        r->next = p;
        r = p;
        scanf("%d",&x);
    }
    r->next = NULL;
    return 0;
}


int length_linklist(Linklist head){
    Lnode *p = head;
    int    j = 0;
    while(p->next != NULL){
        p=p->next;
        j++;
    }
    return p;
}

Linklist get_linklist_number(Linklist head,int i){
    Lnode *p = head;
    int    j = 0;
    while(p != NULL&&j < i){//查找序号需要提前判断下一个节点是否为空
        p = p->next;
        j++;
    }
    return p;//找到了返回结点，未找到返回NULL
}

Linklist get_linklist_data(Linklist head,int x){
    Lnode *p = head->next;
    if(p != NULL&&p->data != x){
        p = p->next;
    }
    return p;
}

int add_linklist_back(Linklist head,int i){
     Lnode *p = get_linklist_number(head,i-1),*s;
     if(p == NULL){ //如果i-1个节点不存在，则不能插入，第i个节点可以不存在。
         perror("add error");
     }else{
         s = (Lnode*)malloc(sizeof(Lnode));
         int x;
         s->data = x;
         s->next = p->next;
         p->next = s;
         return 0; 
     }
}

int add_linklist_front(Linklist head,int i){
    int x;
    Lnode *p = get_linklist_number(head,i),*q,*s;
    if(p == NULL){
        printf("不存在第i个结点，不适用于前插法");
        return -1;
    }else{
        while(q->next != p){
            q = q->next;
        }
        s = (Lnode*)malloc(sizeof(Lnode));
        s->data = x;
        s->next = q->next;
        q->next = s;
        return 0;
    }
}//本质上不存在前插发，前插法是后插发的变形。

int delete_linklist(Linklist head,int i){
    Lnode *p,*q;
    p = get_linklist_number(head,i-1);
    if(p == NULL){
        printf("第i-1个结点不存在");
        return -1;
    }else{
        if(p->next == NULL){
            printf("第i个结点不存在");
            return -1;
        }
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return 0;
}

void backformation_linklist(Linklist head){
    Lnode *p,*q;
    p = head->next;
    head->next = NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}