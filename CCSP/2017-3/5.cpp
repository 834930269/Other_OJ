#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
#define cle(a,val) memset(a,(val),sizeof(a))
#define SI(N) scanf("%d",&(N))
#define SII(N,M) scanf("%d %d",&(N),&(M))
#define SIII(N,M,K) scanf("%d %d %d",&(N),&(M),&(K))
#define rep(i,b) for(int i=0;i<(b);i++)
#define rez(i,a,b) for(int i=(a);i<=(b);i++)
#define red(i,a,b) for(int i=(a);i>=(b);i--)
const ll LINF = 0x3f3f3f3f3f3f3f3f;
#define PU(x) puts(#x);
#define PI(A) cout<<(A)<<endl;
#define DG(x) cout<<#x<<"="<<(x)<<endl;
#define DGG(x,y) cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<endl;
#define DGGG(x,y,z) cout<<#x<<"="<<(x)<<" "<<#y<<"="<<(y)<<" "<<#z<<"="<<(z)<<endl;
#define PIar(a,n) rep(i,n)cout<<a[i]<<" ";cout<<endl;
#define PIarr(a,n,m) rep(aa,n){rep(bb, m)cout<<a[aa][bb]<<" ";cout<<endl;}
const double EPS = 1e-9 ;
/*  ////////////////////////   C o d i n g  S p a c e   ////////////////////////  */
//弧,从from到to的容量为cap,流量为flow的弧当cap=0时,意味此边是反向弧
//当且仅当flow<cap时,该弧存在于残量网络中
struct Edge
{
    Edge(){}
    Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
    int from,to,cap,flow;
};
struct Dinic{
    int n,m,s,t; //节点数,边数
    vector<Edge> edges;//边表。edges[e]和edges[e^1]互为反向弧。
    vector<int> G[maxn]; //邻接表,G[i][j]表示节点i的第j条边在e数组中的序号
    bool vis[maxn]; //BFS使用
    int d[maxn]; //从起点到i的距离
    int cur[maxn]; //当前弧的下标

    //插入弧,原图中的一条弧对应于两个Edge结构体,一个是这条弧本身,另一个是他的反向弧
    //根据插入顺序不难看出,edges[0]和edges[1]互为反向弧,edges[2]和edges[3]
    //一般的,edges[e]和edges[e^1]互为反向弧
    void AddEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        cle(vis,0);
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to] && e.cap>e.flow){//只考虑残量网络中的狐
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a){
        if(x==t || a==0) return a;
        int flow=0,f;
        for(int& i=cur[x];i<G[x].size();++i){//从上次考虑的弧
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(BFS()){
            cle(cur,0);
            flow+=DFS(s,INF);
        }
        return flow;
    }
};

int main(){
    return 0;
}
