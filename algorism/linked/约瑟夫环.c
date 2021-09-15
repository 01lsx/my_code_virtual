#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct cyclenode{
    int id;
    int password;
    struct cyclenode *next;
}Lnode,*Linklist;

//为什么这个函数的出现会有一大堆的问题？🤔
/*void create_information(int &id,int &ipasswd,int i){
     printf("请输入第%d个结点的id:",i+1);
    scanf("%d",&id);
    if(id != -1){
    printf("请输入第%d个结点的password:",i+1);
    scanf("%d",&ipasswd);
}*/

int create_cycle_linklist(Linklist *c_head){
    Lnode *newnode,*point;
    int i=0,id=0,ipasswd=0;
    printf("please attention:if id number = -1,stop create\n");
    printf("please input %dth node id:",i+1);
    scanf("%d",&id);
    if(id != -1){
    printf("please input %dth node password:",i+1);
    scanf("%d",&ipasswd);
    }
    while(id != -1){
        newnode = (Lnode*)malloc(sizeof(Lnode));
        newnode->id = id;
        newnode->password = ipasswd;
        if(*c_head == NULL){
        *c_head = point = newnode;
        point->next = *c_head;
        }else{
            point->next = newnode;
            point = point->next;
            point ->next = *c_head;//相当于是尾插法最后让尾指针指向头结点
        }
        i++;
        printf("please input %dth node id:",i+1);
        scanf("%d",&id);
        if(id != -1){
        printf("please input %dth node password:",i+1);
        scanf("%d",&ipasswd);
        }
    }
    return i;
}
//Linklist create_cycle_node(int id,int passwd)
int show_cycle_linklist(Linklist head){
    Lnode *p = head;
    int i = 0;
    if(p == NULL){
        printf("   the linklist is empty\n");
    }else{
        do{
            if(i == 0){
            printf("   id = %3d  password = %6d\n",p->id,p->password);
            }else{
            printf("    id = %3d  password = %6d\n",p->id,p->password);
            }
            p = p->next;
            i++;
        }while(p != head); 
    }
    return i;
}

int running_killnode_dextro(Linklist *head,int fpswd,int length){
    Lnode *pre,*point,*rm;
    int tempasswd = fpswd,n = 1;
    point = pre = *head;
    while(length != 0){
    for(int i = 1;i < tempasswd;i++){
        point = point->next;
    }  
    while(pre->next != point){
        pre=pre->next;
    }
    rm = point;
    point = point->next;
    pre->next = point;
    tempasswd = rm->password;
    printf("the %dth dequeue`s node id : %3d  passwd : %6d\n",n,rm->id,rm->password);
    free(rm);
    length--;
    n++;
    }
    return length;

}
    
int main(){
    Linklist head = NULL;
    int fpswd = 3,flags=0,length,i,remain;
    char ch;
    while(1){
    system("reset");
    printf("please choise the operation you want: \n\n");
    printf("|choise 1 :create a single cycle linklist    |\n");
    printf("|choise 2 :perform cycle linklist information|\n");
    printf("|chiose 3 :josephus problen by dextro        |\n");
    printf("|choise 0 :exit                              |\n\n");
    printf("please input a number: ");
    scanf("%d",&flags);
    system("reset");
    switch(flags){
        case 1:
        length = create_cycle_linklist(&head);
        printf("the create_cycle_linklist  is over\n");
        printf("the linklist`s length is %d\n",length);
        ch = getchar();
        break;

        case 2:
        printf("  the linklist information is:  \n");
        printf("--------------------------------\n ");
        i = show_cycle_linklist(head);
        printf("---------------------------------\n ");
        printf(" the information perform is over\n");
        ch = getchar(); ch = getchar();//为什么需要两个才能达到效果🤔
        break;
        
        case 3:
        remain = running_killnode_dextro(&head,fpswd,length);
        if(remain != 0){
            printf("empty linklist can`t operating delete!\n");
            exit(1);
        }
        if(remain == 0){
            head = NULL;
        }
        printf("the single cycle`s length is %d\n\n",remain);

        ch = getchar(); ch = getchar();
        break;

        case 0: printf("----sign out\n\n\n"); 
        return 0;
        }
    }
}