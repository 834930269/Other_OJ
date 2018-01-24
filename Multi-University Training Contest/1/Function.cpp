//HDU 6038
#include<bits/stdc++.h>

using namespace std;
const int maxn=100000+100;
const int mod=1e9+7;
typedef long long int lli;
vector<int> G[maxn];
//lowlink[u] == Ϊu��������׷�ݵ�������(���ȱ�����)�����Ƚڵ�v��pre[v]��ֵ.
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;

int a[maxn],b[maxn];

stack<int> S;
map<int,int> A,B;

//�ڽӱ�洢ͼ
void addAdge(int u,int v){
    G[u].push_back(v);
}

inline lli qp(lli aa,lli x){
    if(aa == 0) return 0;
    lli ans = 1;
    for(;x;x>>=1){
        if(x&1) ans = ans*aa % mod;
        aa = aa*aa % mod;
    }
    return ans % mod;
}

void dfs(int u,map<int,int>& T){
    pre[u]=lowlink[u]= ++dfs_clock;
    //��dfs������ջ��Tarjan
    S.push(u);
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(!pre[v]){
            dfs(v,T);
            //����ʱ����lowlink����
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }else if(!sccno[v]){
            //δ����ʱ����low������Ҫͨ��pre����
            lowlink[u]=min(lowlink[u],pre[v]);
        }
    }
    if(lowlink[u]==pre[u]){
        scc_cnt++;
        int cnt=0;
        for(;;){
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            cnt++;
            if(x==u)break;
        }
        T[cnt]++;
    }
}

void Tarjan(int n,map<int,int>& T){
    while(!S.empty()){
        S.pop();
    }
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=0;i<n;++i){
        if(!pre[i]) dfs(i,T);
    }
}

int main(){
    int n,m,kase=0;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;++i){
            scanf("%d",&b[i]);
        }
        //��aTarjan
        for(int i=0;i<n;++i){
            addAdge(i,a[i]);
        }
        Tarjan(n,A);
        for(int i=0;i<n;++i){
            G[i].clear();
        }
        //��bTarjan
        for(int i=0;i<m;++i){
            addAdge(i,b[i]);
        }
        Tarjan(m,B);
        for(int i=0;i<m;++i){
            G[i].clear();
        }

        long long ans=1;
        map<int,int>::iterator it1;
        map<int,int>::iterator it2;
        for(it1=A.begin();it1!=A.end();it1++){
            long long tmp=0;
            for(it2=B.begin();it2!=B.end();it2++){
                if(it1->first%it2->first==0){
                    tmp=tmp+it2->second*it2->first;
                }
                //printf("%d %d : %d %d\n",it1->first,it2->first,it1->second,it2->second);
            }
            ans=ans*qp(tmp,it1->second)%mod;
        }
        printf("Case #%d: %lld\n",++kase,ans);
        A.clear();
        B.clear();
    }
    return 0;
}
