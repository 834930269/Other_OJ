#include<bits/stdc++.h>
using namespace std;

int move1[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int move2[8][2]={{0,-1},{0,1},{-1,0},{1,0},
                 {1,-1},{1,1},{-1,-1},{-1,1}};
char mp[110][110];
int N,kase=1;
int vis1[110][110],vis2[110][110];

void init(){
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
}

bool check(int x,int y){
    if(x>=N || y>=N || x<0 || y<0 || mp[x][y]=='0')
        return false;
    return true;
}

void dfs4(int x,int y){
    if(!check(x,y) || vis1[x][y]) return;
    vis1[x][y]=1;
    for(int i=0;i<4;++i){
        int nx=x+move1[i][0],ny=y+move1[i][1];
        dfs4(nx,ny);
    }
}

void dfs8(int x,int y){
    if(!check(x,y) || vis2[x][y]) return;
    vis2[x][y]=1;
    for(int i=0;i<8;++i){
        int nx=x+move2[i][0],ny=y+move2[i][1];
        dfs8(nx,ny);
    }
}

int main(){
    while(~scanf("%d",&N) && N){
        init();
        for(int i=0;i<N;++i){
            scanf("%s",mp[i]);
        }
        int ans4=0,ans8=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(mp[i][j]=='1' && !vis1[i][j]){
                    ans4++,dfs4(i,j);
                }
                if(mp[i][j]=='1' && !vis2[i][j]){
                    ans8++,dfs8(i,j);
                }
            }
        }
        printf("Case %d: %d %d\n\n",kase++,ans4,ans8);
    }
    return 0;
}
