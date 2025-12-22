//9) DFS, BFS uygulaması
#include <stdio.h>

#define N 5

typedef struct { int q[128]; int f,r; } Q;
void qinit(Q* s){ s->f=s->r=0; }
int qempty(Q* s){ return s->f==s->r; }
void qpush(Q* s,int v){ s->q[s->r++]=v; }
int qpop(Q* s){ return s->q[s->f++]; }

void dfs(int g[N][N], int vis[N], int u){
    vis[u]=1;
    printf("%d ", u);
    for(int v=0; v<N; v++) if(g[u][v] && !vis[v]) dfs(g,vis,v);
}

void bfs(int g[N][N], int start){
    int vis[N]={0};
    Q q; qinit(&q);
    vis[start]=1; qpush(&q,start);
    while(!qempty(&q)){
        int u=qpop(&q);
        printf("%d ", u);
        for(int v=0; v<N; v++){
            if(g[u][v] && !vis[v]){
                vis[v]=1;
                qpush(&q,v);
            }
        }
    }
}

int main(void){
    int g[N][N]={
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0}
    };
    int vis[N]={0};
    dfs(g,vis,0);
    printf("\n");
    bfs(g,0);
    printf("\n");
    return 0;
}
