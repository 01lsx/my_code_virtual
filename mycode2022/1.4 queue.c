#include<stdio.h>
#define MAX 10
#define OK 1
#define ERROR 0
typedef int QElemType;
typedef int Status;
    
    typedef struct{
    QElemType data[MAX]; 
    int front;
    int rear;
}SqQueue;                                           //循环队列
    typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;                                   //链队列节点
    typedef struct{
        QueuePtr front,rear;
}LinkQueue;                                         //链队列头指针

Status InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAX) % MAX;
}

Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear + 1) % MAX == Q->front)
    return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX;

    return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front == Q->rear)
    return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX;

    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
        if(p){
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
Status DeQueue(LinkQueue *Q,QElemType *e){
        if(Q->rear == Q->front){
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front = p->next;
    
        if(Q->rear == p){
        Q->rear = Q->front;        
    }

    free(p);
    return OK;
}


