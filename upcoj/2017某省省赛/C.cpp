#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
///W是能力,C是coin
int CC[30][10],WW[30][10],C[30][10],W[30][10],eq[30];
int T,N,KI,ca=1;
int max_power,M;
void dfs(int th,int sum,int cost){
    if(cost>M) return;
    if(th>N) return;
    max_power=max(max_power,sum);
    for(int i=0;i<=eq[th];++i)
        dfs(th+1,sum+WW[th][i],cost+CC[th][i]);
}

int main(){
    scanf("%d",&T);
    while(T--){
        max_power=-1;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i){
            scanf("%d",&eq[i]);
            for(int j=0;j<eq[i];++j){
                scanf("%d%d",&W[i][j],&C[i][j]);
            }
        }
        for(int i=0;i<N;++i){
            CC[i][0]=WW[i][0]=0;
            for(int j=1;j<=eq[i];++j){
                CC[i][j]=CC[i][j-1]+C[i][j-1];
                WW[i][j]=WW[i][j-1]+W[i][j-1];
            }
        }
        dfs(0,0,0);
        printf("Case #%d: %d\n",ca++,max_power);
    }
    return 0;
}
