#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,ans,kase=0;
    while(~scanf("%lld%lld",&a,&b)){
        if(b<=a){
            printf("Case #%lld: %lld\n",++kase,b);
            continue;
        }else{
            long long loop=(a-1)<<1,rg=b-a;
            long long res=rg%loop;
            if(res==a-1) ans=a-1;
            else if(res==0) ans=a;
            else
                ans=res>a-1?res-a+1:res;
            printf("Case #%lld: %lld\n",++kase,ans);
        }
    }
    return 0;
}
