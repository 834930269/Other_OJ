#include<bits/stdc++.h>
using namespace std;
const int MAX_M=200000+10;
const int maxn=200000+10;
int N,M;
int A,B,C;

struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,from,to;
    bool operator<(const HeapNode& rhs)const{
        return d>rhs.d;
    }
};

struct Kruskal{
    int n,m;///点数和边数
    vector<Edge> edges;///边表
    vector<int> G[maxn];///每个节点出发的边编号
    priority_queue<HeapNode> Q;

    ///并查集
    int fa[maxn];///父亲
    int ra[maxn];///高度
    ///init:初始化(点数)
    ///find_Root:查找树的根
    ///unite:合并x和y所属集合
    ///same:判断x和y是否是同一个集合
    void init(int n){
        this->n=n;
        for(int i=0;i<n;++i){
            fa[i]=i;
            ra[i]=0;
            G[i].clear();
        }
        edges.clear();
    }
    int find_Root(int x){
        if(fa[x]==x){
            return x;
        }else{
            return fa[x]=find_Root(fa[x]);
        }
    }
    void unite(int x,int y){
        x=find_Root(x);
        y=find_Root(y);
        if(x==y) return;

        if(ra[x]<ra[y]){
            fa[x]=y;
        }else{
            fa[y]=x;
        }
    }
    bool same(int x,int y){
        return find_Root(x)==find_Root(y);
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size()-1;
        G[from].push_back(m-1);
        Q.push((HeapNode){dist,from,to});
    }

    int kruskal(){
        HeapNode h;
        while(!Q.empty()){
            if(find_Root(N)==find_Root(1))break;
            h=Q.top();Q.pop();
            if(find_Root(h.from)==find_Root(h.to))continue;
            unite(h.from,h.to);
        }
        printf("%d\n",h. d);
    }
}K;

int main(){
    while(~scanf("%d%d",&N,&M)){
        K.init(N);
        for(int i=0;i<M;++i){
            scanf("%d%d%d",&A,&B,&C);
            K.AddEdge(A,B,C);
        }
        K.kruskal();
    }
    return 0;
}
