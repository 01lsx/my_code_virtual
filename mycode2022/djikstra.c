#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 65535
#define MAX 9
typedef struct Vertextype{
    char name[3];
}Vertextype;
typedef struct Mgraph{
    Vertextype vex[MAX];
    int length[MAX][MAX];
    int numVertex,numEdge;
}   Mgraph;

void ShortestPath_djikstra(Mgraph G,int v0,int *P,int *D){
    int i,w,k,min;
    int final[MAX];
    for(i = 0;i < G.numVertex;i++){                 // 初始化
        final[i] = 0;
        P[i] = 0;
        D[i] = G.length[0][i];
    }
    final[v0] = 1;
    for(i = 1;i < G.numVertex;i++){
            min = INFINITY;
            for(w = 0;w < G.numVertex;w++){
            if(!final[w] && D[w] < min){
            k = w;
            min = D[w];
            }
        }
    final[k] = 1;
    for(w = 0;w < G.numVertex;w++){
                if(!final[w] && (min + G.length[k][w]) < D[w]){
                D[w] = min + G.length[k][w];
                P[w] = k;
            }
        }
    }
    // for(int i = 0;i < MAX;i++){
    //     printf("%d \t",(*P)[i]);
    // }   printf("\n");
    // for(int i = 0;i < MAX;i++){
    //     printf("%d \t",(*D)[i]);
    // }   printf("\n");
}
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
        INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,7,4,0
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
int main(){
    int P[MAX];
    int D[MAX];
    Mgraph G;
    G = *Create_Mgraph();
    for(int i = 0;i < MAX;i++){                  //打印邻接矩阵
            for(int j = 0;j < MAX;j++){
            printf("%d \t",G.length[i][j]);
        }   printf("\n");
    }
    printf("\n\n");
    ShortestPath_djikstra(G,0,P,D);
    for(int i = 0;i < MAX;i++){
        printf("%d \t",i);
    }   printf("\n");
    for(int i = 0;i < MAX;i++){
        printf("%d \t",P[i]);
    }   printf("\n");
    for(int i = 0;i < MAX;i++){
        printf("%d \t",D[i]);
    }   printf("\n");
}


