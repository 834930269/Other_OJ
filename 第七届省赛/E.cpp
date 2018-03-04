#include<bits/stdc++.h>
using namespace std;
const int maxn=110;

int T,N,M;
char mp[maxn][maxn];
int dist[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

bool check(int x,int y){
    if(x<1 || x>M || y<1 || y>N) return false;
    return true;
}

int main(){
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d",&M,&N);
        for(int i=1;i<=M;++i){
            scanf("%s",mp[i]+1);
        }
        for(int i=1;i<=M;++i){
            for(int j=1;j<=N;++j){
                if(mp[i][j]=='#'){
                    for(int k=0;k<4;++k){
                        int x=i+dist[k][0],y=j+dist[k][1];
                        if(check(x,y)){
                            if(mp[x][y]=='#')continue;
                            int room=0;
                            for(int kk=0;kk<4;++kk){
                                int xx=x+dist[kk][0],yy=y+dist[kk][1];
                                if(check(xx,yy)){
                                    if(mp[xx][yy]=='#')++room;
                                }
                            }
                            if(room==1)ans++;
                        }else ++ans;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
