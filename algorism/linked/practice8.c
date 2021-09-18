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

void operate_function(Linklist *head1,Linklist *head2,int i,int length,int j){
    
}

int main(){
    int length,i,j;
    Linklist La,Lb,temp;
    char ch;
    printf("if data = -1,stop creating\n");
    printf("creating La:\n");   
    int lengtha = create_linklist(&La);
    printf("create La over,length is %d\n",lengtha);
    sleep(2);
    system("reset");
    printf("if data = -1,stop creating\n");
    printf("creating Lb:\n");
    int lengthb = create_linklist(&Lb);
    printf("create Lb over,length is %d\n",lengthb); 
    sleep(2);
    system("reset");
    printf("the linklist La`s length is %d\n",lengtha);
    printf("the linklist Lb`s length is %d\n\n",lengthb);
    printf("now you want to rm a length La node to Lb Linklist\n");
    while(1){
        printf("please input the La`s first operating node and length:\n");
        printf("i = ");
        scanf("%d",&i);
        if(i<1||i>lengtha){
            printf("La is not long enough\n");
            continue;
        }
        printf("length = ");
        scanf("%d",&length);
        if((i+length)>lengtha){
            printf("La is not long enough\n");
            continue;
        }
        break;
    }
    while(1){
        printf("plesae input the insert node of Lb\n");
        printf("Lb`s node = ");
        scanf("%d",&j);
        if(j<1||j>lengthb){
            printf("Lb is not long enough\n");
            continue;
        }
        printf("assignment is over,please press anykesy to continue\n");
        ch = getchar();
        system("reset");
        break;
    }
    printf("|the La`s first node is %d  |\n|the operate length is %d   |\n|the Lb`s operate node is %d|\n",i,length,j);

    return 0;
}