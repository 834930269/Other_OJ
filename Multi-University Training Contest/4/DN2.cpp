#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
LL ans,l,r,k,T;
LL d(LL num){
    int cnt=0;
    for(LL i=1;i<=num;++i){
        if(num%i==0)cnt++;
    }
    return cnt;
}

LL powe(LL a){
    LL qs=1;
    for(int i=1;i<=k;++i){
        qs*=a;
    }
    return qs;
}

int main(){
    scanf("%lld",&T);
    while(T--){
        ans=0;
        scanf("%lld",&l);
        printf("     %lld\n",d(l));
    }
    return 0;
}
