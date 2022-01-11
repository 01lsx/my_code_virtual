#include<stdio.h>
#include<stdlib.h>
#define ERROR 0;
#define OK 1;
typedef int Status;
typedef char SElemType;

    typedef struct StackNode{                                       //链栈使用无头链表
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
    typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;                                                         //栈顶结构体
    typedef struct LNode{
    char data;
    struct LNode *next;
}LNode,*LNodePtr;


LNodePtr Transfer(LNodePtr head);
int Calculate(LNodePtr heads);
void Input(LNodePtr head);
Status Judgement(LNodePtr head);
Status Push(LinkStack *a,char b);
Status Pop(LinkStack *a,char *b);

int main(){
    LNode *head = (LNode*)malloc(sizeof(LNode));
    Input(head);
    //int n = Judgement(head);
    //if(n == 0){
        //printf("输入有误，请重新输入\n");
    //}
    int sum = Calculate(head);
    printf("sum = %d",sum);
    
    
    // LNode *p = head->next;                                       //打印输入的数据链表
    // while(p){
    //     printf("%c",p->data);
    //     p = p->next;
    // }

}

void Input(LNodePtr head){
        char ch;
        LNode *p,*q = head;
        scanf("%c",&ch);
        while(ch != 32){                                            //Linux下如何判断回行💣
        p = (LNode*)malloc(sizeof(LNode));
        p->data = ch;
        p->next = NULL;
        q->next = p;
        q = p;
        scanf("%c",&ch);
    }
}

Status Judgement(LNodePtr head){
    
    LNode *p = head->next;
            while(p){
            if((p->data >= 'a' && p->data <= 'z') || (p->data >='A' && p->data <= 'Z')){
            return ERROR;
        }   else{
            p = p->next;
        }
    }
            if((head->next->data == '+') || (head->next->data == '-') || (head->next->data == '*') || (head->next->data == '/') ){
            return ERROR;
        }
    LNode *q = head->next;
            while(q->next){
            q = q->next;
        }
            if((q->data == '+') || (q->data == '-') || (q->data == '*') || (q->data == '/') ){
            return ERROR;
        }  

    return OK;
    //如果是字母，则报错 *
    //如果四则运算符符号出现在最前面或者最后面，则报错 *
    //右括号的左边不能有符号，左括号的右边不能有符号
    //四则运算符号周围不能有四则运算符
    //左括号和右括号的数量必须相同
    //左括号必须在右括号前面
}

LNodePtr Transfer(LNodePtr head){
    LNodePtr heads = (LNodePtr)malloc(sizeof(LNode));
    LNode *q = heads,*u,*p;
    LinkStack Mark;
    StackNode* Node = (LinkStackPtr)malloc(sizeof(StackNode));
    while(head->next){
        if((head->next->data >= '0') && (head->next->data <= '9')){
            
            p = (LNodePtr)malloc(sizeof(LNode));                    //数字直接入数据链表
            p->data = head->next->data;
            p->next = NULL;
            q->next = p;
            q = p;
            
            u = head->next;                                         
            head->next = u->next;
            free(u);
        
        }
        //如果是数字，直接输出 *
        //将符号存入一个结构体数组中，结构体成员为符号和所对应优先级别，当进行比较时
        //head数据链表拿出的符号在数组中进行搜索，并查看优先等级 D1
        //Mark链栈栈顶元素的符号在数组中进行搜索，并查看优先级 D2 D1和D2进行比较
        //D1 >= D2 head数据链中的节点入Mark栈
        
        //D1 < D2 Mark栈栈顶元素依次出栈进入heads数据链表，最后将D2入Mark栈
        //如果是右括号，则单独讨论，输出栈顶符号，直到左括号出栈后结束
        //最后将所有的符号输出
    }
    return heads;
}

int Calculate(LNodePtr heads){
    int sum = 0;
    LinkStack *Number = (LinkStack *)malloc(sizeof(LinkStack));
    LNodePtr P = heads->next;
    char ca,cb,result;
    int a,b;
                while(P){
                if((P->data >= '0') && (P->data <= '9')){
                Push(Number,P->data);
        }       
                else{
                
                Pop(Number,&ca); a = (int)ca - 48; printf("a = %d\n",a);
                Pop(Number,&cb); b = (int)cb - 48; printf("b = %d\n",b);
                if(P->data == '+'){
                sum = a + b;
                Push(Number,sum);
            }   else if(P->data == '-'){
                sum = b - a;
                Push(Number,sum);
            }   else if(P->data == '*'){
                sum = a*b;
                Push(Number,sum);
            }   else if(P->data == '/'){
                    if(b == 0){
                    return ERROR;
                }
                    sum = b/a;
                    Push(Number,sum);
            }
        }
    P = P->next;
    }
    Pop(Number,&result);
    sum = (int)result;
    printf("%d \n",Number->count);
    //遇到数字入栈 *
    //遇到符号取两个栈顶两个数字与运算符进行计算，计算结果再入数字栈 *
    //直到最后 *
    return sum;
}

Status Push(LinkStack *a,char b){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = b;
    s->next = a->top;
    a->top = s;
    a->count++;
    return OK;
}

Status Pop(LinkStack *a,char *b){
        if(a->top == NULL || a->count == 0){
        return ERROR;
    }
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    *b = a->top->data;
    s = a->top;
    a->top = a->top->next;
    a->count--;
    free(s);
    return OK;
}





