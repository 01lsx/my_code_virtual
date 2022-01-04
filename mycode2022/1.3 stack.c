#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define ERROR 0;
#define OK    1;
typedef int Status;
typedef int SElemType;
    
    typedef struct{
    SElemType data[MAXSIZE];
    int top;
}SqStack;                                               //顺序栈
    typedef struct{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;                                         //共享栈
    typedef struct StackNode{                           
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;                               //链栈节点
    typedef struct LinkStack{                       
    LinkStackPtr top;
    int count;
}LinkStack;                                             //链栈头指针结构体

Status push(SqStack *S,SElemType e){
        if(S->top == MAXSIZE-1){
        return ERROR;
    }
    
    S->top++;
    S->data[S->top] = e;
    return OK;
}
Status pop(SqStack *S,SElemType *e){
        if(S->top == -1){
        return ERROR;
    }
    
    *e = S->data[S->top];
    S->top--;
    return OK;
}

Status Push(SqDoubleStack *S,SElemType e,int StackNumber){
        if(S->top1 + 1 == S->top2){
        return ERROR;
    }
            if(StackNumber == 1){
            S->data[++S->top1] = e;
        }   else if(StackNumber == 2){
            S->data[--S->top2] = e;
        }
        return OK;
}
Status Pop(SqDoubleStack *S,SElemType *e,int StackNumber){
            if(StackNumber == 1){
            if(S->top1 == -1){
            return ERROR;
        }
            *e = S->data[S->top1--];
    }       else if(StackNumber == 2){
            if(S->top2 == MAXSIZE -1){
            return ERROR;
            *e = S->data[S->top2++];
        }
    }
    return OK;
}

Status Pushlink(LinkStack *S,SElemType e){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}
Status Poplink(LinkStack *S,SElemType *e){
        LinkStackPtr p;
        if(S->top == NULL){
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}


