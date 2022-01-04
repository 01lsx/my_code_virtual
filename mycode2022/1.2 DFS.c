#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
int visit[MAX];
    
    typedef struct VertexType{
    char name[3];
}VertexType;
    typedef struct Mgraph{
    VertexType vex[MAX];
    int length[MAX][MAX];
    int numVertex,numEdge;
}Mgraph;
    typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
    typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAX];
    typedef struct GraphAdjList{
    AdjList adjlist;
    int numVertex,numEdge;
}GraphAdjList;

Mgraph* Create_Mgraph(){
    int i,j;
    Mgraph *G;
    G = (Mgraph *)malloc(sizeof(Mgraph));
    int a[MAX][MAX] = {
        0,1,5,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,
        1,0,3,7,5,INFINITY,INFINITY,INFINITY,INFINITY,
        5,3,0,INFINITY,1,7,INFINITY,INFINITY,INFINITY,
        INFINITY,7,INFINITY,0,2,INFINITY,3,INFINITY,INFINITY,
        INFINITY,5,1,2,0,3,6,9,INFINITY,
        INFINITY,INFINITY,7,INFINITY,3,0,INFINITY,5,INFINITY,
        INFINITY,INFINITY,INFINITY,3,6,INFINITY,0,2,7,
        INFINITY,INFINITY,INFINITY,INFINITY,9,5,2,0,4,
        INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,7,4,0
    };
         for(i = 0;i < MAX;i++){
             for(j = 0;j < MAX;j++){
             G->length[i][j] = a[i][j];
        }
    }

        strcpy(G->vex[0].name,"v0");
        strcpy(G->vex[1].name,"v1");
        strcpy(G->vex[2].name,"v2");
        strcpy(G->vex[3].name,"v3");
        strcpy(G->vex[4].name,"v4");
        strcpy(G->vex[5].name,"v5");
        strcpy(G->vex[6].name,"v6");
        strcpy(G->vex[7].name,"v7");
        strcpy(G->vex[8].name,"v8");

        G->numVertex = MAX;
        G->numEdge = 16;
        
    //         for(int i = 0;i < G->numVertex;i++){         //打印邻接矩阵
    //         for(int j = 0;j < G->numVertex;j++){
    //         printf("%d \t",G->length[i][j]);
    //     }   printf("\n");
    // }

        return G;
}

void Createhelper(GraphAdjList *G,int i,int j,int w){
    EdgeNode *e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->weight = w;
    e->next = G->adjlist[i].firstedge;
    G->adjlist[i].firstedge = e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = i;
    e->weight = w;
    e->next = G->adjlist[j].firstedge;
    G->adjlist[j].firstedge = e;
}

GraphAdjList* Create_GraphAdjList(){
    GraphAdjList *G;
    G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    
        strcpy(G->adjlist[0].data.name,"v0");
        strcpy(G->adjlist[1].data.name,"v1");
        strcpy(G->adjlist[2].data.name,"v2");
        strcpy(G->adjlist[3].data.name,"v3");
        strcpy(G->adjlist[4].data.name,"v4");
        strcpy(G->adjlist[5].data.name,"v5");
        strcpy(G->adjlist[6].data.name,"v6");
        strcpy(G->adjlist[7].data.name,"v7");
        strcpy(G->adjlist[8].data.name,"v8");

        Createhelper(G,0,1,1);
        Createhelper(G,0,2,5);
        Createhelper(G,1,2,3);
        Createhelper(G,1,3,7);
        Createhelper(G,1,4,5);
        Createhelper(G,2,4,1);
        Createhelper(G,2,5,7);
        Createhelper(G,3,6,3);
        Createhelper(G,4,6,6);
        Createhelper(G,4,7,9);
        Createhelper(G,5,7,5);
        Createhelper(G,6,7,2);
        Createhelper(G,7,8,4);
        Createhelper(G,3,4,2);
        Createhelper(G,4,5,3);
        Createhelper(G,6,8,7);

        G->numVertex = MAX;
        G->numEdge = 16;

    //         EdgeNode *e;                                //打印邻接表所对应下标
    //         for(int i = 0;i < MAX;i++){
    //         e = G->adjlist[i].firstedge;
    //         printf("%d :",i);
    //         while(e){
    //         printf("%d ",e->adjvex);
    //         e = e->next;
    //     }
    //         printf("\n");
    // }
        
        return G;
}
void DFS_Mgraph(Mgraph G,int i){
        visit[i] = TRUE;
        printf("%d ",i);
        for(int j = G.numVertex -1;j > 0;j--){
        if( !visit[j] && G.length[i][j] != 0 && G.length[i][j] != INFINITY)
        DFS_Mgraph(G,j);
    }
}
void DFS_Traverse1(Mgraph G){
        for(int i = 0;i < G.numVertex;i++){
        visit[i] = FALSE;
    }
        for(int j = 0;j < G.numVertex;j++){
        if(!visit[j])
        DFS_Mgraph(G,j);
    }
}

void DFS_ALgraph(GraphAdjList G,int i){
        EdgeNode *e;
        e = G.adjlist[i].firstedge;
        visit[i] = TRUE;
        printf("%d ",i);
        while(e){
        if(!visit[e->adjvex])
        DFS_ALgraph(G,e->adjvex);
        e = e->next;
    }
}
void DFS_Traverse2(GraphAdjList G){
        for(int i = 0;i < G.numVertex;i++){
        visit[i] = FALSE;
    }
        for(int i = 0;i < G.numVertex;i++){
        if(!visit[i])
        DFS_ALgraph(G,i);
    }
}

int main(){
    int c;
    Mgraph *G1;
    GraphAdjList *G2;
    char ch;
    while(1){
        
        system("reset");
        printf("  ------------------------  \n");
        printf("  select the choise you want\n");
        printf("1. Mgraph DFS               \n");
        printf("2. GraphAdjList DFS         \n");
        printf("3. exit                     \n");
        printf("  ------------------------  \n");
        scanf("%d",&c);

        switch(c){
        
        case 1:
        
        G1 = Create_Mgraph();
        DFS_Traverse1(*G1);
        ch = getchar();
        ch = getchar();
        break;
        
        
        case 2:
        
        G2 = Create_GraphAdjList();
        DFS_Traverse2(*G2);
        ch = getchar();
        ch = getchar();
        break;
    
        case 3:
        
        return 0;
        
        }
    }
}