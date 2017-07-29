///线段树法
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxnode=2000050;

int b[maxnode],N;
int maxv[maxnode];

void build(int o,int l,int r){
    if(l==r){
        if(l>N) return;///预先分配2*N个结点
        scanf("%d",&maxv[o]);maxv[o]-=l;
        return;
    }
    int mid=(l+r)>>1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}

int query(int o,int l,int r,int ll,int rr){
    if(l>=ll&&r<=rr) return maxv[o];
    int ma=-1,mid=(l+r)>>1;
    if(mid>=ll) ma=max(ma,query(o<<1,l,mid,ll,rr));
    if(rr>mid) ma=max(ma,query(o<<1|1,mid+1,r,ll,rr));
    return ma;
}

void update(int o,int l,int r,int p,int val){
    if(l==r){
        maxv[o]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid)update(o<<1,l,mid,p,val);
    else update(o<<1|1,mid+1,r,p,val);
    maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}

int main(){
    while(~scanf("%d",&N)&&N){
        build(1,1,2*N);
        for(int i=1;i<=N;++i) scanf("%d",&b[i]);
        sort(b+1,b+1+N);
        LL ans=0;
        for(int i=N+1;i<=2*N;++i){
            int k=query(1,1,2*N,b[i-N],i-1);
            update(1,1,2*N,i,k-i);
            ans=(ans+k)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
