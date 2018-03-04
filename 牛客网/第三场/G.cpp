#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(LL N){
    LL ans=N;
    LL k[4]={2,5,11,13};
    for(int seq=1;seq<16;++seq){
        LL reg=1;
        int d=0;
        if(seq&1) reg*=k[0],d++;
        if(seq&2) reg*=k[1],d++;
        if(seq&4) reg*=k[2],d++;
        if(seq&8) reg*=k[3],d++;
        if(d&1) ans-=(N/reg);
        else ans+=(N/reg);
    }
    printf("%lld\n",ans);
}

int main(){
    LL n;
    while(cin>>n){
        solve(n);
    }
    return 0;
}
