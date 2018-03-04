#include<bits/stdc++.h>
using namespace std;
const int mod=1000;
int main(){
    int A,B;
    while(cin>>A>>B&&A+B){
        int ans=1;
        for(int i=1;i<=B;++i){
            ans=((ans%mod)*(A%mod))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
