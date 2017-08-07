#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
///区间更新
typedef long long ll;

const int DAT_SIZE=(1<<18)-1;
const int MAX_N=100000+10;
const int MAX_Q=100000+10;

int N,Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q],R[MAX_Q],X[MAX_Q];

///线段树,a维护区间应加值,b维护区间和
ll data[DAT_SIZE],datb[DAT_SIZE];

///对区间[a,b]同时加x
///k是节点编号,对应的区间是[l,r)
void add(int a,int b,int x,int k,int l,int r){
    if(a<=l&&r<=b){
        data[k]+=x;
    }else if(l<b && a<r){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,(k<<1)+1,l,(l+r)>>1);
        add(a,b,x,(k<<1)+2,(l+r)>>1,r);
    }
}

///计算[a,b)的和
ll sum(int a,int b,int k,int l,int r){
    if(b<=l || a>=r){
        return 0;
    }else if(a<=l && r<=b){
        return data[k]*(r-l)+datb[k];
    }else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,(k<<1)+1,l,(l+r)>>1);
        res+=sum(a,b,(k<<1)+2,(l+r)>>1,r);
        return res;
    }
}

///下标0开头的线段树初始化
///开区间[a,b)
void solve(){
    for(int i=0;i<N;++i){
        add(i,i+1,A[i],0,0,N);
//        printf("\nadd: %d -> %d\n",i,A[i]);
    }
    for(int i=0;i<Q;++i){
        if(T[i]=='C'){
            add(L[i],R[i]+1,X[i],0,0,N);
        }else{
            printf("%lld\n",sum(L[i],R[i]+1,0,0,N));
        }
    }
}

int main(){
    while(scanf("%d%d",&N,&Q)==2){
        memset(data,0,sizeof(data));
        memset(datb,0,sizeof(datb));
        for(int i=0;i<N;++i){
            scanf("%d",&A[i]);
        }
        ///区间是[0...N)所以要减一
        for(int i=0;i<Q;++i){
            scanf("%*c%c",&T[i]);
            if(T[i]=='C'){
                scanf("%d%d%d",&L[i],&R[i],&X[i]);
                L[i]-=1;R[i]-=1;
            }else{
                scanf("%d%d",&L[i],&R[i]);
                L[i]-=1;R[i]-=1;
            }
        }
        solve();
    }
    return 0;
}
