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
//��,��from��to������Ϊcap,����Ϊflow�Ļ���cap=0ʱ,��ζ�˱��Ƿ���
//���ҽ���flow<capʱ,�û������ڲ���������
struct Edge
{
    Edge(){}
    Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
    int from,to,cap,flow;
};
struct Dinic{
    int n,m,s,t; //�ڵ���,����
    vector<Edge> edges;//�߱�edges[e]��edges[e^1]��Ϊ���򻡡�
    vector<int> G[maxn]; //�ڽӱ�,G[i][j]��ʾ�ڵ�i�ĵ�j������e�����е����
    bool vis[maxn]; //BFSʹ��
    int d[maxn]; //����㵽i�ľ���
    int cur[maxn]; //��ǰ�����±�

    //���뻡,ԭͼ�е�һ������Ӧ������Edge�ṹ��,һ��������������,��һ�������ķ���
    //���ݲ���˳���ѿ���,edges[0]��edges[1]��Ϊ����,edges[2]��edges[3]
    //һ���,edges[e]��edges[e^1]��Ϊ����
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
                if(!vis[e.to] && e.cap>e.flow){//ֻ���ǲ��������еĺ�
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
        for(int& i=cur[x];i<G[x].size();++i){//���ϴο��ǵĻ�
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
