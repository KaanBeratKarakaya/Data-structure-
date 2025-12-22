//8) Array olarak verilen graph’dan cluster çıkarma
#include <stdio.h>

#define N 6

void dfs(int g[N][N], int vis[N], int u){
    vis[u]=1;
    for(int v=0; v<N; v++){
        if(g[u][v] && !vis[v]) dfs(g,vis,v);
    }
}

int main(void){
    int g[N][N]={
        {0,1,0,0,0,0},
        {1,0,1,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,0}
    };
    int vis[N]={0};
    int comp=0;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            comp++;
            dfs(g,vis,i);
        }
    }
    printf("%d\n", comp);
    return 0;
}
