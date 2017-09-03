#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#define N 102
#define M 102
using namespace std;
typedef pair<int,int> PAIR;
int go[][2] = {0,1,1,0,-1,0,0,-1};
bool vis[N][M]={0};
struct node{
    int x,y,t;
    node(int a,int b,int c){x=a;y=b;t=c;}
};
int n,m,t;
PAIR time[N][M];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<t;++i){
        int x,y;
        cin>>x>>y;
        cin>>time[x][y].first>>time[x][y].second;
    }
    queue<node> Q;
    Q.push(node(1,1,0));
    while(!Q.empty()){
        node tmp=Q.front();Q.pop();
        vis[tmp.x][tmp.y]=false;
        if(tmp.x==n&&tmp.y==m){printf("%d\n",tmp.t);break;}
        for(int i=0;i<4;++i){
            int p=tmp.x+go[i][0];
            int q=tmp.y+go[i][1];
            if(p==0||q==0||p==n+1||q==m+1)continue;
            if(time[p][q].first<=tmp.t+1 && time[p][q].second>=tmp.t+1 || vis[p][q])continue;
            vis[p][q]=true;
            Q.push(node(p,q,tmp.t+1));
        }
    }
    return 0;
}
