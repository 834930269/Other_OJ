#include<bits/stdc++.h>
using namespace std;
const int maxn=100050;
int T,num[maxn],ind[maxn],ans;
int dp[maxn];
int main(){
    scanf("%d",&T);
    for(int kase=1;kase<=T;++kase){
        int N;
        fill(ind,ind+maxn,0);
        scanf("%d",&N);
        for(int i=0;i<N;++i)
            scanf("%d",&num[i]);
        dp[0]=num[0];ind[0]=0;ans=0;
        for(int i=1;i<N;++i){
            if(dp[i-1]>=0){
                dp[i]=dp[i-1]+num[i];
                ind[i]=ind[i-1];
            }else{
                dp[i]=num[i];
                ind[i]=i;
            }
            if(dp[ans]<dp[i]) ans=i;
        }
        printf("Case %d:\n%d %d %d\n",kase,dp[ans],ind[ans]+1,ans+1);
        if(kase!=T) printf("\n");
    }
    return 0;
}
