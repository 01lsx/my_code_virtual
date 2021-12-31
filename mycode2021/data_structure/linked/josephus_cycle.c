#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

typedef struct cyclenode{
    int id;
    int password;
    struct cyclenode *next;
    struct cyclenode *prior;
}Lnode,*Linklist;

void create_cycle_linklist(Linklist *c_head,int *quantity){
    srand(time(NULL));
    Lnode *newnode,*front,*point;
    int id=0,ipasswd=0;
    printf("please attention:if id number = -1,stop create\n");
    printf("please input %dth node id:",quantity[0]+1);
    scanf("%d",&id);
    if(id != -1){
    //printf("please input %dth node password:",i+1);
    //scanf("%d",&ipasswd);
    ipasswd = rand()%10+1;
    printf("the %dth id`s password is %d\n",quantity[0]+1,ipasswd);
    }
    while(id != -1){
        newnode = (Lnode*)malloc(sizeof(Lnode));
        newnode->id = id;
        newnode->password = ipasswd;
        if(*c_head == NULL){
        *c_head = front = point = newnode;
        point->next = *c_head;
        front->prior = point;//
       //*c_head->prior = point; //为什么这个是不可行的是🤔
        }else{
            point = front = *c_head;//这里为了第二次进行追加结点
            while(point->next != *c_head){
                point = point->next;
            }
            point->next = newnode;
            newnode->prior = point;
            point = point->next;
            point ->next = front;
            front->prior = point;//相当于是尾插法最后让尾指针指向头结点
        }
        quantity[0]++;
        printf("please input %dth node id:",quantity[0]+1);
        scanf("%d",&id);
        if(id != -1){
        //printf("please input %dth node password:",i+1);
        //scanf("%d",&ipasswd);
        ipasswd = rand()%10+1;
        printf("the %dth id`s password is %d\n",quantity[0]+1,ipasswd);
        }
    }
}

int show_cycle_linklist_dextro(Linklist head){
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
        p = p->next; i++;
        }while(p != head); 
    } return i;
}

int show_cycle_linklist_counter(Linklist head){
    Lnode *f = head;
    int i = 0;
    if(f == NULL){
        printf("   the linklist is empty\n");
    }else{
        f = head->prior;
        do{
        if(i == 0){
            printf("   id = %3d  password = %6d\n",f->id,f->password);
        }else{
            printf("    id = %3d  password = %6d\n",f->id,f->password);
        }
        f = f->prior;
        i++;
        }while(f != head->prior);
    } return i;
}

void running_killnode_dextro(Linklist *head,int *quantity){
    Lnode *pre,*point,*rm;
    char ch;
    int tempasswd = 1,n = 1;
    point = pre = *head;
    printf("the linklist`s length is %d\n",quantity[0]);
    while(1){
        printf("please select the first one(smaller than length):");
        scanf("%d",&tempasswd);
        if(tempasswd > quantity[0]||tempasswd < 1){
            printf("the first one select error,please select again\n");
        }else{
            printf("please press anykeys to continue\n");
            ch = getchar(); ch = getchar();
            system("reset");
            break;    
        }
    }
    while(quantity[0] != 0){
    for(int i = 1;i < tempasswd;i++){
        point = point ->next;
    }
    while(pre->next != point){
        pre=pre->next;
    }
    rm = point;
    point = point->next;
    pre->next = point;
    point->prior = pre;
    tempasswd = rm->password;
    printf("the %dth dequeue`s node id : %3d  passwd : %6d\n",n,rm->id,rm->password);
    free(rm);
    
    quantity[0]--; n++;
    }
}

void running_killnode_counter(Linklist *head,int *quantity){
    Lnode *point,*pre,*rm;
    char ch;
    int tempasswd = 1,n = 1;
    point = pre = *head;
    point = point ->prior;
    printf("the linklist`s length is %d\n",quantity[0]);
    while(1){
        printf("please select the first one(smaller than length):");
        scanf("%d",&tempasswd);
        if(tempasswd > quantity[0]||tempasswd < 1){
            printf("the first one select error,please select again\n");
        }else{
            printf("please press anykeys to continue\n");
            ch = getchar(); ch = getchar();
            system("reset");
            break;    
        }
    }
    while(quantity[0] != 0){
        for(int i = 1;i < tempasswd;i++){
            point = point->prior; 
        }
        while(pre->prior != point){
            pre = pre->prior;
        }
        rm = point;
        point = point->prior;
        pre->prior = point;
        point ->next = pre;
        tempasswd = rm->password;
        printf("the %dth dequeue`s node id : %3d  passwd : %6d\n",n,rm->id,rm->password);
        free(rm);
        quantity[0]--; n++;
    }
}
    
int main(){
    Linklist head = NULL;
    int fpswd = 3,flags=0,length,i,print = 3,del = 3,quantity[2];
    quantity[0] = 0;
    char ch;
    while(1){
    system("reset");
    printf("please choise the operation you want: \n\n");
    printf("|choise 1 :create a single cycle linklist    |\n");
    printf("|choise 2 :perform cycle linklist information|\n");
    printf("|chiose 3 :josephus problem running          |\n");
    printf("|choise 0 :exit                              |\n\n");
    printf("please input a number: ");
    scanf("%d",&flags);
    system("reset");
    switch(flags){
        case 1://🎇
        create_cycle_linklist(&head,quantity);
        printf("the create_cycle_linklist  is over\n");
        printf("the linklist`s length is %d\n",quantity[0]);
        printf("please press anykeys to exit\n");
        ch = getchar();
        break;
        case 2://🎇
        while(1){
        if(print == 0){
            print = 3;
            break;
        }
        system("reset");
        printf("please search the order of the perform：\n");
        printf("choise 1 : dextro clockwise order\nchoise 2 : counter clockwise order\n");
        printf("choise 0 : exit\n\n");
        printf("please select :");
        scanf("%d",&print);
        printf("please press anykeys to continue\n");
        ch = getchar(); //ch = getchar();
        system("reset");
        switch(print)
        {
            case 1://🎆
            printf("  the linklist information is:  \n");
            printf("--------------------------------\n ");
            i = show_cycle_linklist_dextro(head);
            printf("---------------------------------\n ");
            printf(" the information perform is over\n");
            printf("please press anykeys to exit\n");
            ch = getchar();
            break;
            case 2://🎆
            printf("  the linklist information is:  \n");
            printf("--------------------------------\n ");
            i = show_cycle_linklist_counter(head);
            printf("---------------------------------\n ");
            printf(" the information perform is over\n");
            printf("please press anykeys to exit\n");
            ch = getchar();
            break;
            case 0: break;//🎆
            }
        } break;
        case 3://🎇
        while(1){
        if(del == 0){
            del = 3;
            break;
        }    
        system("reset");
        printf("please select the order of the josephus problem:\n");
        printf("chiose 1 : josephus problem by dextro order\n");
        printf("choise 2 : josephus problem by counter order\n");
        printf("choise 0 : exit\n\n");
        printf("please select: ");
        scanf("%d",&del);
        printf("please press anykeys to continue\n");
        ch = getchar();
        system("reset");
        switch(del){
            case 1: //🎆
            if(head == NULL){
                printf("empty linklist can`t operating delete!\n");
                printf("please press anykeys to exit\n");
                ch = getchar();
                break;
            }
            running_killnode_dextro(&head,quantity);
            if(quantity[0] != 0){
                printf("running_killnode_dextro is error\n");
                exit(1);
            }else if(quantity[0] == 0){
                head = NULL;
            }
            printf("the single cycle`s length is %d\n\n",quantity[0]);
            printf("please press anykeys to exit\n");
            ch = getchar();
            break;
            case 2://🎆
            if(head == NULL){
                printf("empty linklist can`t operating delete!\n");
                printf("please press anykeys to exit\n");
                ch = getchar();
                break;
            }
            running_killnode_counter(&head,quantity);
            if(quantity[0] != 0){
                printf("running_killnode_dextro is error\n");
                exit(1);
            }else if(quantity[0] == 0){
                head == NULL;
            }
            printf("the single cycle`s length is %d\n\n",quantity[0]);
            printf("please press anykeys to exit\n");
            ch = getchar();
            break;
            case 0: break;//🎆
            }
        }break;//switch 中case 套swtich一定要记得break出case
        case 0://🎇
        printf("----sign out\n\n\n");  return 0;
        }
    }
}