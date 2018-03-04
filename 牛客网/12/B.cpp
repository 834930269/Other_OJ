#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int has_key;
    int cnt,x,y;
}node;

char mp[510][510];
int h,w,sx,sy;
//об,ио,ср,вС
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int vis[2][600][600];

void bfs(){
    bool yes=false;
    queue<node> st;
    st.push((Node){0,0,sx,sy});
    vis[0][sx][sy]=1;
    while(!st.empty()){
        node nd=st.front();st.pop();
        if(mp[nd.x][nd.y]=='E'){
            printf("%d\n",nd.cnt);
            return;
        }
        if(mp[nd.x][nd.y]=='K'){
            nd.has_key=1;
        }
        int nx,ny;
        for(int i=0;i<4;++i){
            nx=nd.x+mv[i][0],ny=nd.y+mv[i][1];
            if(vis[nd.has_key][nx][ny]) continue;
            if(mp[nx][ny]=='W') continue;
            if(mp[nx][ny]=='D' && !nd.has_key) continue;
            vis[nd.has_key][nx][ny]=1;
            st.push((Node){nd.has_key,nd.cnt+1,nx,ny});
        }
    }
    printf("-1\n");
}

int main(){
    cin>>h>>w;
    bool flag=true;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<h;++i){
        scanf("%s",mp[i]);
        for(int j=0;flag && j<w;++j){
            if(mp[i][j]=='S'){
                sx=i,sy=j;
                flag=false;
            }
        }
    }
    bfs();
    return 0;
}
