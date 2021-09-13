//头插法 尾插法
//前插 后插
//正序插 倒序插
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct Node{
    int         data;
    struct Node *next;
}Lnode,*Linklist;

void sys_err(const char *str){
    perror(str);
    exit(1);
}

Linklist create_linklist_head(){
    int      x;
    Lnode    *p;
    Linklist head = (Linklist)malloc(sizeof(Lnode));
    head->next = NULL;
    scanf("%d",&x);
    while(x != -1){
        p = (Lnode *)malloc(sizeof(Lnode));
        p->next = head->next;
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
    return j;
}

Lnode *get_linklist_number(Linklist head,int i){
    Lnode *p = head;
    int    j = 0;
    while(p->next != NULL&&j < i){//查找序号需要提前判断下一个节点是否为空
        p = p->next;
        j++;
    }//如果j=i说明找到了结点，返回p，p对应想找的结点。如果i大于链表的长度，那么p会编程NULL，返回P即可。
    return p;//找到了返回结点，未找到返回NULL
}

Lnode *get_linklist_data(Linklist head,int x){
    Lnode *p = head->next;
    while(p != NULL&&p->data != x){
        p = p->next;
    }
    return p;
}

int insert_linklist_back(Linklist head,int i){
     int x;
     Lnode *p = get_linklist_number(head,i-1),*s;
     if(p == NULL){ //如果i-1个节点不存在，则不能插入，第i个节点可以不存在。
         printf("these place can`t insert node");
         return -1;
     }else{
         s = (Lnode*)malloc(sizeof(Lnode));
         printf("请输入要插入结点的数据：");
         scanf("%d",&x);
         s->data = x;
         s->next = p->next;
         p->next = s; 
     }
     return 0;
}

int insert_linklist_front(Linklist head,int i){
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

void purify_linklist(Linklist head){
    Lnode *p,*q,*r;
    p = head->next;
    if(p!=NULL)
        while(p->next){//p的指针域不指向NULL，即未到链表尾
            q = p;
            while(q->next){//q的指针不指向NULL，即未到链表尾
                if(q->next->data == p->data){
                    r = q->next;
                    q->next = r->next;
                    free(r);
                }
                else q=q->next;
            }
            p = p->next;
        }
}

void difference(Linklist Ha,Linklist Hb){
    Lnode *pre,*p,*r,*q;
    pre = Ha;//
    p=Ha->next;
    while(p!=NULL){
        q=Hb->next;
        while(q!=NULL&&q->data!=p->data)
            q=q->next;
        if(q!=NULL){
            r = p;
            pre->next = p->next;
            p=p->next;
            free(r);
        }else{
            pre = p;
            p=p->next;//让pre始终跟在p的前面，因为如果需要删除需要目标节点的前一个结点。
        }
    }
}

int main(int argc,char *argv[]){
    int i=1,j=1,x,n,o;
    printf("creating first linklist:\n");
    Linklist head = create_linklist_head();
    printf("creat linklist1 is finished\n");
    Lnode *p = head->next;
    int number1 = length_linklist(head);
    printf("linklist length is %d\n",number1);
    
    //查询某个结点的数据
  /*Lnode *test,*find = head;
    printf("请选择想要查询的方式：\n");
    printf("根据序号查数据请按<1>\n");
    printf("根据数据查序号请按<2>\n");
    scanf("%d",&n);
    switch(n){
        case 1:
        printf("请输入要查询的结点号：");
        scanf("%d",&i);
        test = get_linklist_number(head,i);
        if(test == NULL){
            printf("the find number is error\n");
            return -1;
        }
        printf("the %d node`s data is %d\n",i,test->data);  break;
        case 2:
        printf("请输入要查询的数据：");
        scanf("%d",&x);
        test = get_linklist_data(head,x);
        if(test == NULL){
            printf("the finding data is error");
            return -1;
        }
        printf("finding the data %d `s nodenumber finish\n",test->data);
        while(find->next){
              if(find->next == test){
                  break;
              }
              else{find = find->next; j++;}
        }
        printf("the data %d`s node is %dth",test->data,j); break;
    }*/

    //插入结点
  /*printf("请输入想要插入的结点序号：");
    scanf("%d",&i);
    o = insert_linklist_back(head,i);
    if(o == -1){
        sys_err("insert error");
    }*/
    
    //删除结点
  /*printf("请输入要删除的结点序号：");
    scanf("%d",&x);
    o = delete_linklist(head,x);
    if(o == -1){
        printf("the node you will delete is error\n");
        return -1;
    }*/

    //插入操作需要目标结点前的结点存在，删除结点需要目标结点前和目标节点同时存在

     //链表数据逆置 
  /*backformation_linklist(head);
    //printf("%d\n",p->data);
    p=head->next;//一开始p指向了第一个结点，逆置后指向最后一个结点。    
    */

    //删除重复结点
    /*printf("删除重复结点中...\n");
    purify_linklist(head);
    printf("删除重复结点成功！\n");
    number2 = length_linklist(head);
    printf("the changing linklist length is %d\n",number2);
    */

    //两个集合的差集
  /*printf("creating second linklist:\n");
    Linklist head1 = create_linklist_head();
    printf("creat linklist2 is finished\n");
    int number1 = length_linklist(head1);
    printf("linklist length is %d\n",number);
    difference(head,head1);*/
    
    //查看各结点数据
    while(p != NULL){
        printf(" node %dth`s data is %d\n",i++,p->data);
        p = p->next;
    }
    sleep(1);
    return 0;
}

/*单循环链表
单链表的尾指针指向链表的头结点
RA为链表1的尾结点，RB为链表2的尾结点,将两单循环链表合并
p = RA->next;
RA->next = RB->next->next;
free(RB->next);
RB->next = p;//循环链表首尾相连
*/

//双向链表
/*
在单链表中，如果想要找某个结点的前驱，必须从头节点开始遍历，直到找到一个节点的指针域指向当前节点，这个结点就是我们要找的
双向循环链表
空表的头指针指向头节点，前指针域prior指向后指针域next,后指针域next指向前指针域prior
非空表的头指针指向头结点，头结点的前指针域prior指向尾结点数据，尾节点的后指针域next指向头节点。

双向链表的定义：
typedef struct ldnode{
    datatype data;
    struct ldnode *prior,*next;
}DLNode,*DLinklist;
双向链表中的结点有如下关系：
p->prior->next = p;
p = p->next->prior;
也就是说通过当前已知结点可以找到前驱结点和后继结点，根据这些基础可以推导双向链表的插入和删除

在指定结点p前插入结点s//先处理p之前的结点，再处理p，因为前面的结点是通过p找到的。
s->prior = p->prior;
p->prior->next = s ;
s->next = p;
p->prior = s;

删除指定的结点p
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);
*/

//静态链表
/*
typedef struct{
    Datatype data;
    int next;
}Snode;
Snode sd[maxsize];
int SL;
这里的next表示下标，称为静态指针，静态指针也叫“游标”，也就是用游标来模拟指针。
*/