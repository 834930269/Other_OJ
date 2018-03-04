#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int maxn = 1e5+7;

LL C[maxn];
///逆元
LL inv[maxn];
void init_(){
    inv[1]=1;
    for(int i=2;i<maxn;++i){
        inv[i]=(MOD-MOD/i)*1ll*inv[MOD%i]%MOD;
    }
}

///快速幂模求逆元
LL quick_mod(LL x, int n){
    LL ret = 1;
    while(n){
        if(n & 1) ret = ret * x % MOD;
        x = x * x %MOD;
        n >>= 1;
    }
    return ret;
}

void init(int t){
    C[0]=1;
    for(int i=1;i<=t;++i){
        C[i]=C[i-1]*(t-i+1)*1ll%MOD*inv[i]%MOD;
        //printf("Num: %d %lld, INV: %lld\n",i,C[i],inv[i]);
    }
}
//判断是否同奇同偶
bool same(int x,int y){
    if((x&1)^(y&1)) return false;
    return true;
}

int query(int t,int d){
    if(t&1){
        return t/2-d/2;
    }
    return t/2+(d-1)/2;
}

int main(){
    init_();
    int n,T,w;
    while(~scanf("%d%d%d",&n,&T,&w)){
        init(T);
        LL ans=0;
        for(int i=1;i<=n;++i){
            int x,c;
            scanf("%d%d",&x,&c);
            int dist=abs(x-w);
            if(!same(T+1,dist) && dist<T+1){
                ans=(ans+c*C[query(T+1,dist)]%MOD)%MOD;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
