#include<bits/stdc++.h>
#define fill(x) memset(x,0,sizeof(x))
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn=100000+10;
int n;
long long dp[maxn],a,dt[100000+10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&n,&a);
        for(int i=1;i<=n;++i){
            dp[i]=1000000000000000000;
            scanf("%lld",&dt[i]);
            for(int j=i-1;j>=1;--j){
                long long t;
                if(dt[i]-dt[j]>30)break;
                if(dp[j]!=1000000000000000000) t=dp[j];
                else t=0;
                dp[i]=min(dp[i],t+(1<<(dt[i]-dt[j]))+a);
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
