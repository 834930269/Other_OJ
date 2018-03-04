#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL N;

LL euler(LL n){
    LL res=n,a=n;
    for(LL i=2;i*i<=a;++i){
        if(a%i==0){
            res=res/i*(i-1);
            while(a%i==0)a/=i;
        }
    }
    if(a>1)res=res/a*(a-1);
    return res;
}

int main(){
    while(~scanf("%lld",&N)){
        LL ans=0;
        for(LL i=1;i*i<=N;++i){
            if(N%i==0){
                ans+=(i*euler(N/i));
                if(i*i!=N){
                    ans+=((N/i)*euler(i));
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
