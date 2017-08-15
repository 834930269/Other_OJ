#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long pow_mod(long long a,long long n){
    long long text=1;
    while (n){
        if (n&1) text = (text%mod)*(a%mod)%mod;
        a = (a%mod)*(a%mod)%mod;
        n >>= 1;
    }
    return text;
}
int main(){
    long long n,k;
    while(~scanf("%lld%lld",&n,&k)){

    }
    return 0;
}
