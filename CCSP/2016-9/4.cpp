#include<bits/stdc++.h>
using namespace std;

const int maxn=1000000;
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,u;
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};
int n,m,d[maxn],ans[maxn],cost;
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
void AddEdge(int from,int to,int dist){
    edges.push_back((Edge){from,to,dist});
    m=edges.size();
    G[from].push_back(m-1);
}
void dijskra(int s){
    priority_queue<HeapNode> Q;
    for(int i=0;i<=n;++i) d[i]=0x3f3f3f3f;
    d[s]=0;
    memset(done,false,sizeof(done));
    memset(ans,0,sizeof(ans));
    Q.push((HeapNode){0,s});
    while(!Q.empty()){
        HeapNode x=Q.top();Q.pop();
        int u=x.u;
        if(done[u]) continue;
        done[u]=true;
        for(int i=0;i<G[u].size();++i){
            Edge &e=edges[G[u][i]];
            if(d[e.to]>d[u]+e.dist){
                d[e.to]=d[u]+e.dist;
                ans[e.to]=e.dist;
                Q.push((HeapNode){d[e.to],e.to});
            }else if(d[e.to]==d[u]+e.dist){
                ans[e.to]=min(ans[e.to],e.dist);
            }
        }
    }
}
int main(){
    int M;
    scanf("%d%d",&n,&M);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        AddEdge(a,b,c);
        AddEdge(b,a,c);
    }
    dijskra(1);cost=0;
    for(int i=0;i<=n;++i){
        cost+=ans[i];
    }
    printf("%d\n",cost);
    return 0;
}
