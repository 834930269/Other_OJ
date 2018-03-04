#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,A,B;

int main(){
    cin>>n>>k>>A>>B;
    if(k==1 || k>n){
        cout<<(n-1)*A<<endl;
    }else{
        LL ans=0;
        while(n!=1){
            if(n%k){
                LL r=n-(n/k)*k;
                if(r==n)r=n-1;
                ans+=r*A;
                n-=r;
            }else{
                ans+=min(B,(n-n/k)*A);
                n/=k;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
