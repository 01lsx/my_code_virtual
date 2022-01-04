#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9
#define INFINITY 65535
typedef struct Vertextype{
    char name[3];
}Vertextype;
typedef struct Mgraph{
    Vertextype vex[MAX];
    int length[MAX][MAX];
    int numVertex,numEdge;
}Mgraph;

Mgraph* Create_Mgraph(){
    Mgraph *G;
    G = (Mgraph *)malloc(sizeof(Mgraph));
    int i,j;
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
        return G;
}

void ShortestPath_Floyd(Mgraph G,int P[][MAX],int D[][MAX]){
    int k,v,w;
            for(v = 0;v < MAX;v++){                         //初始化
            for(w = 0;w < MAX;w++){
            D[v][w] = G.length[v][w];
            P[v][w] = w;
        }
    }
                    for(k = 0;k < MAX;k++){
                    for(v = 0;v < MAX;v++){
                    for(w = 0;w < MAX;w++){
                    if(D[v][w] > D[v][k] + D[k][w]){        //点v和点w连通，v和w都与k连通，且v-k-w < v-w
                    D[v][w] = D[v][k] + D[k][w];            
                    P[v][w] = P[v][k];
                }
            }
        }
    }
            for(v = 0;v < G.numVertex;v++){
            for(w = 0;w < G.numVertex;w++){
            printf("v%d - v%d weight : %d",v,w,D[v][w]);
            k = P[v][w];                                    // 获得第一个路径顶点下标
            printf(" path : %d",v);                         // 打印源点
                while(k != w){
                printf(" -> %d",k);
                k = P[k][w];
            }
            printf(" -> %d\n",w);
        }
        printf("\n");
    }
}

int main(){
    int Path[MAX][MAX],Weight[MAX][MAX];
    Mgraph *G;
    G = (Mgraph *)malloc(sizeof(Mgraph));
    G = Create_Mgraph();
    //         for(int i = 0;i < G->numVertex;i++){
    //         for(int j = 0;j < G->numVertex;j++){
    //         printf("%d \t",G->length[i][j]);
    //     }   printf("\n");
    // }
    ShortestPath_Floyd(*G,Path,Weight);
    printf("P矩阵\n");
    for(int i = 0;i < G->numVertex;i++){
            for(int j = 0;j < G->numVertex;j++){
            printf("%d \t",Path[i][j]);
        }   printf("\n");
    }       printf("\n");
    printf("D矩阵\n");
    for(int i = 0;i < G->numVertex;i++){
            for(int j = 0;j < G->numVertex;j++){
            printf("%d \t",Weight[i][j]);
        }   printf("\n");
    }       printf("\n");
}