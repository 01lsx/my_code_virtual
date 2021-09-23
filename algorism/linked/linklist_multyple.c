#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
  int data;
  struct node *next;
}Lnode,*Linklist;

void create_linklist(Linklist *head,int *quantity,int count){
    char ch;
    printf("if data = -1,stop creating\n");
    printf("creating %dth linklist:\n",count+1);   
    Lnode *newnode,*point;
    int x=0;
    printf("please input the %dth node`s data：",quantity[count]+1);
    scanf("%d",&x);
    while(x != -1){
        newnode = (Lnode*)malloc(sizeof(Linklist));
        newnode->data = x;
        newnode->next = NULL;
        if(*head == NULL){
            *head = point = newnode;
        }else{
            point->next = newnode;
            point = newnode;
        }
        quantity[count]++;
        printf("please input the %dth node`s data：",quantity[count]+1);
        scanf("%d",&x);
    }
    printf("create %dth linklist over,length is %d\n",count+1,quantity[count]);
    sleep(2);
    system("reset");
}

void show_function(Linklist *head,int count,int *quantity){//sizeof(count)/4=链表个数
    Lnode *point;
    int j,number = 0,i;
    for(i = 0;i < count;i++){
        j = 1;
        printf("the %dth linklist data: \n",i+1);
        printf("-------------------------\n");
        if(head[i]==NULL){
            printf("|  the linklist is emyty  |\n");
        }else{
            point = head[i];
            while(point != NULL){
                printf("| %dth node`s data is  %d |\n",j++,point->data);
                point = point->next;
                number++;
            }
        }
        printf("-------------------------\n");
        printf("length is %d\n",quantity[i]);
        printf("\n\n\n");
    }
}

void operate_function(int num1,int num2,int a,int length,int b,int *quantity,Linklist *head){
    int number = 1;
    Lnode *point1,*pre1,*point2,*pre2;
    point1 = pre1 = head[num1-1];
    for(int i = 1;i < a;i++){
                point1 = point1->next;
            }//找到第一个链表中需要操作的第一个结点
    if(a>1){
    while(pre1->next != point1){
        pre1 = pre1->next;
        }
    }//pre1是不变的，变的是point1
    point2 = pre2 = head[num2-1];
    while(point2->next != NULL){
        point2 = point2->next;
        number++;
    }
    point2 = head[num2-1];
    if(b == quantity[num2-1]+1){
        for(int i = 1;i < b-1;i++){
        point2 = point2->next;}
    }else{
        for(int i = 1;i < b;i++){
        point2 = point2->next;}
    }
    for(int i = 0;i < length;i++){
    if(a == 1){
        head[num1-1] = point1 = point1->next;
        quantity[num1-1]--;
        if(b == 1){
            if(i == 0){
                pre1->next = point2; pre2 = pre1; pre1 = point1; head[num2-1] = pre2;
                quantity[num2-1]++;
            }else{
                while(pre1->next != point1){
                    pre1 = pre1->next;
                    }               
                    pre1->next = point2; pre2->next = pre1; pre1 = point1;
                    quantity[num2-1]++;
                }
            
            }else if(b == number+1){
                point2->next = pre1; pre1->next = NULL; point2 = point2->next; pre1 = point1;
                quantity[num2-1]++;
            }else{
                while(pre2->next != point2){
                pre2 = pre2->next;
                }
                pre2->next = pre1; pre1->next = point2; pre1 = point1;
                quantity[num2-1]++;
                }
        }else{
            quantity[num1-1]--;
            if(b == 1){
                if(i == 0){
                    pre1->next = point1->next; point1->next = point2; head[num2 - 1] = point1;
                    point1 = pre1->next; pre2 = head[num2 - 1];
                    quantity[num2-1]++;
                }else{
                    while(pre2->next != point2){
                        pre2=pre2->next;
                    }
                    pre1->next = point1->next; point1->next = point2;
                    pre2->next = point1; point1 = pre1->next;
                    quantity[num2-1]++;
                }
            }else if(b == number+1){
                point2->next = point1; pre1->next = point1->next; point2 = point2->next;
                point2->next = NULL; point1 = pre1->next;
                quantity[num2-1]++;
            }else{
                while(pre2->next != point2){
                    pre2=pre2->next;
                }
                pre2->next = point1;
                pre1->next = point1->next;
                point1->next = point2;
                point1 = pre1->next;
                quantity[num2-1]++;
            }
        }
    }
}

int main(){
    int length,a,i=0,b,quantity[10]={0,0,0,0,0,0,0,0,0,0};
    int count = 0,n,flags;
    int num1=0,num2=0;
    Linklist L1,L2,L3,L4,L5,L6,L7,L8,L9,L10;
    Linklist head[10] = {L1=NULL,L2=NULL,L3=NULL,L4=NULL,L5=NULL,L6=NULL,L7=NULL,L8=NULL,L9=NULL,L10=NULL};
    char ch;
    while(1){
    system("reset");
    printf("     muptiple linklist operation:    \n");
    printf("the whole quantity of the linklist is [%d]\n",count);
    printf("|chiose 1 : create linklist          |\n");
    printf("|chiose 2 : show linklist information|\n");
    printf("|choise 3 : remove node operation    |\n");
    printf("|chiose 0 : exit                     |\n\n");
    printf("please select the operation you want : ");
    scanf("%d",&flags);
    system("reset");
    switch(flags){
        case 1:
        printf("please input the number of linklist you want to create:");
        scanf("%d",&n);
        if(n > 10||n < 0){
            printf("the quantity of the linklist you want is error\n");
            printf("please input anykeys to continue\n");
            ch = getchar(); ch = getchar();
            system("reset");
            break;
        }
        system("reset");
    for(int q = 0;q < n;q++){
        create_linklist(&head[i],quantity,count);//count属于是标志量
        count++; i++;
        } break;
        case 2:
        show_function(head,count,quantity);
        printf("please press anykeys to continue\n");
        ch = getchar(); ch = getchar();
        break;
        case 3:
        if(count < 2 ){
            printf("the linklist is not enough,please create new linklist\n");
            printf("please press anykeys to continue\n");
            ch = getchar(); ch = getchar();
        }
        printf("you want remove some node from the first list to second list\n");
        printf("please select two linklist:\n");
        while(1){
            printf("select the first linklist:");
            scanf("%d",&num1);
            if(head[num1-1] == NULL){
                printf("the first linklist you select is empty,please select again\n");
                continue;
            }else break;
        }
        while(1){    
            printf("select the second linklist:");
            scanf("%d",&num2);
            if(num2 == num1){
                printf("the second linklist you select is same with first,please select again\n");
                continue;
            }
            if(head[num2-1] == NULL){
                printf("the second linklist you select is empty,please select again\n");
                continue;
            }else break;
        }
        printf("the first  linklist is %dth linklist,the length is %d\n",num1,quantity[num1-1]);
        printf("the second linklist is %dth linklist,the length is %d\n",num2,quantity[num2-1]);
        while(1){
        printf("please input the first linklist`s first operating node and length:\n");
        printf("a = ");
        scanf("%d",&a);
        if(a<1||a>quantity[num1-1]){
            printf("the first linklist is not long enough\n");
            continue;
        }
        printf("length = ");
        scanf("%d",&length);
        if((a+length-1)>quantity[num1-1]){
            printf("the first linklist is not long enough\n");
            continue;
        }
        break;
    }
    while(1){
        printf("plesae input the insert node of second linklist\n");
        printf("b = ");
        scanf("%d",&b);
        if(b<1||b>quantity[1]+1){
            printf("Lb is not long enough\n");
            continue;
        }
        printf("assignment is over,please press anykesy to continue\n");
        ch = getchar();
        system("reset");
        break;
        }
        printf("|the first list`s first node is   %d|\n|the operate length is        %d|\n|the second`s operate node is %d|\n",a,length,b);
        printf("operating...");
        operate_function(num1,num2,a,length,b,quantity,head);
        break;
        case 0: return 0;
        }
    }
}
