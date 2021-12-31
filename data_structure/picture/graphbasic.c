#include<stdio.h>
#include<malloc.h>
typedef int EdgeType;
typedef char VertexType;
typedef int Boolean;
#define TRUE 1
#define FALSE  0
#define maxvertex 100
#define maxedge 99
#define INFINITY 65535
Boolean visited[maxvertex];
//邻接矩阵
typedef struct Mgraph{
    VertexType vexs[maxvertex];
    EdgeType arc[maxvertex][maxvertex];
    int numVertexes,numEdges;
}Mgraph;

//边表节点
typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
// 顶点表节点
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[maxvertex];
// 邻接表
typedef struct GraphAdjList{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;

// 边集数组
typedef struct{
    int begin;
    int end;
    int weight;
}Edge;

void CreateMgraph(Mgraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    for(i = 0;i < G->numVertexes;i++){
        printf("请输入第%d个节点的符号",i+1);
        scanf(&G->vexs[i]);
    }
    for(i = 0;i < G->numVertexes;i++){
        for(j = 0;j < G->numVertexes;j++){
            G->arc[i][j] = INFINITY;
        }
    }
    for(k = 0;k < G->numEdges;k++){
        printf("输入边(vi,vj)上的下标i，j和权w:\n");
        scanf("%d %d %d",&i,&j,&k);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

void CreateALGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("请输入图的顶点数和边数：\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    for(i = 0;i < G->numVertexes;i++){
        scanf(&G->adjlist[i].data);
        G->adjlist[i].firstedge = NULL;
    }
    for(k = 0;k < G->numEdges;k++){
        printf("请输入边(vi,vj)上的顶点序号：\n");
        scanf("%d %d",&i,&j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e;
    }
}
// 邻接矩阵深度优先搜索，递归思想
void DFSTraverse1(Mgraph G){
    int i;
    for(i = 0;i < G.numVertexes;i++){
        visited[i] = FALSE;}// 将标记初始化
    for(i = 0;i < G.numVertexes;i++){
        if(!visited[i])
            DFS1(G,i);
    }
}
void DFS1(Mgraph G,int i){
    int j;
    visited[i] = TRUE;
    printf("%c ",G.vexs[i]);
    for(j = 0;j < G.numVertexes;j++){
       if(G.arc[i][j] == 1 && !visited[j])
        DFS1(G,j);
    }
}
// 邻接矩阵广度优先遍历
void BFSTraverse1(Mgraph G){
    int i,j;
    Queue Q;
    for(i = 0;i < G.numVertexes;i++){//最外层循环在做最后的检查
        if(!visited[i]){
            visited[i] = TRUE;
            printf("%c ",G.vexs[i]);
            EnQueue(&Q,i); //入队
            while(!QueueEmpty(Q)){
                DeQueue(&Q,&i); //将队列中的元素取出，赋值给i
                for(j = 0;j < G.numVertexes;j++){
                    if(G.arc[i][j] == 1 && !visited[j]){
                        visited[j] = TRUE;
                        printf("%c ",G.vexs[j]);
                        EnQueue(&Q,j); //入队
                    }
                }
            }
        }
    }
}

// 邻接表深度优先搜索，递归思想
void DFSTraverse2(GraphAdjList GL){
    int i;
    for(i = 0;i < GL.numVertexes;i++){
        visited[i] = FALSE;
    }
    for(i = 0;i < GL.numVertexes;i++){
        if(!visited[i])
            DFS2(GL,i);
    }
}
void DFS2(GraphAdjList GL,int i){
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ",GL.adjlist[i].data);
    p = GL.adjlist[i].firstedge;
    while(p){
        if(!visited[p->adjvex])
            DFS2(GL,p->adjvex);
        p = p->next;
    }
}

// 邻接表广度优先遍历
void BFSTraverse2(GraphAdjList GL){
    int i;
    EdgeNode *p;
    Queue Q;
    for(i = 0;i < GL.numVertexes;i++){
        visited[i] = FALSE;}
    Initqueue(Q);// 对队列进行初始化
    for(i = 0;i < GL.numVertexes;i++){
        if(!visited[i]){
            visited[i] = TRUE;
            EnQueue(&Q,i);
            while(!QueueEmpty(Q)){
                DeQueue(&Q,&i);
                p = GL.adjlist[i].firstedge;
                while(p){
                    if(!visited[p->adjvex]){
                        visited[p->adjvex] = TRUE;
                        printf("%c ",GL.adjlist[p->adjvex].data);
                        Enqueue(&Q,p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}

// prim算法生成最小生成树
void MiniSpanTree_Prim(Mgraph G){
    int min,i,j,k;
    int adjvex[maxvertex];
    int lowcost[maxvertex];
    lowcost[0] = 0; //初始化第一个权值为0，即v0加入生成树
    adjvex[0] = 0; //初始化第一个顶点v0下标为0
    for(i = 0;i < G.numVertexes;i++){
        lowcost[i] = G.arc[0][1]; //将v0顶点与之有边的权值存入数组
        adjvex[i] = 0; //初始化都为v0的下标
    }
    for(i = 1;i < G.numVertexes;i++){
        min = INFINITY;
        j = 1;k = 0;
        while(j < G.numVertexes){
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k] = 0;
        for(j = 0;j < G.numVertexes;j++){
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j]){
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}

// kiuskal算法生成最小生成树
int Find(int *parent,int f){
    while(parent[f] > 0)
        f = parent[f];
    return f;
}
void MiniSpanTree_Kruskal(Mgraph G){
    int i,n,m;
    Edge edges[maxedge];
    int parent[maxvertex]; //定义一个数组判断边与边是否形成环路
    // ...省略G转化为边集数组edges并按权由小到大排序
    for(i = 0;i < G.numVertexes;i++){
         parent[i] = 0;} //初始化数组为0
    for(i = 0;i < G.numEdges;i++){
        n = Find(parent,edges[i].begin);
        m = Find(parent,edges[i].end);
        if(n != m){ //如果n与m不等，说明此边没有与现有生成树形成环路
            parent[n] = m; //将此边的结尾顶点放在下标为起点的parent中 
            printf("(%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}
