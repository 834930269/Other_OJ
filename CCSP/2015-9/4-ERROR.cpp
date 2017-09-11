
//Ko算法,但感觉不太对= =,没做出来
#include<bits/stdc++.h>
using namespace std;

const int maxn=20000;

vector<int> G[maxn];
vector<int> RG[maxn];
stack<int> fg;
bool inv[maxn];
int n,m,ans;

void dfs(int ind){
    fg.push(ind);
    inv[ind]=false;
    for(int i=0;i<G[ind].size();++i){
        if(inv[G[ind][i]])dfs(G[ind][i]);
    }
}

void rdfs(int ind){
    inv[ind]=false;
    for(int i=0;i<RG[ind].size();++i){
        if(inv[RG[ind][i]])dfs(RG[ind][i]);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int from,to;
        scanf("%d%d",&from,&to);
        G[from].push_back(to);
        RG[to].push_back(from);
    }
    memset(inv,true,sizeof(inv));
    for(int i=1;i<=n;++i){
        if(inv[i])dfs(i);
    }
    memset(inv,true,sizeof(inv));
    ans=0;
    for(int i=0;i<fg.size();++i){
        int ite=fg.top();fg.pop();
        if(inv[ite]){
            rdfs(ite);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
