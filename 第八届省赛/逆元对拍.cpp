#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int maxn = 1e5+7;

LL inv[maxn];
LL C[maxn];
void init_(){
    inv[1]=1;
    for(int i=2;i<maxn;++i){
        inv[i]=(MOD-MOD/i)*1ll*inv[MOD%i]%MOD;
    }
}

LL quick_mod(LL x, int n){
    LL ret = 1;
    while(n){
        if(n & 1) ret = ret * x % MOD;
        x = x * x %MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    init_();
    for(int i=1;i<maxn;++i){
        if(quick_mod(i,MOD-2)!=inv[i]){
            printf("%lld %lld\n",inv[i],quick_mod(i,MOD-2));
        }
    }
    return 0;
}
