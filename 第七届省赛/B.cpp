#include<bits/stdc++.h>
using namespace std;
const int maxn=45;
int Fb[maxn],M;
int vis[maxn],has_ans;

void init(){
    Fb[0]=1;
    Fb[1]=2;
    for(int i=2;i<maxn;++i){
        Fb[i]=Fb[i-1]+Fb[i-2];
        //printf("%d\n",Fb[i]);
    }

}

void solve(int N){
    stack<int> ans;
    int mx=maxn;
    while(N!=0){
        int ind=lower_bound(Fb,Fb+mx,N)-Fb;
        if(Fb[ind]>N)ind-=1;
        N=N-Fb[ind];
        ans.push(Fb[ind]);
    }
    printf("%d=",M);
    int t=0;
    while(!ans.empty()){
        if(!t){
            printf("%d",ans.top());t++;
        }else printf("+%d",ans.top());
        ans.pop();
    }
    printf("\n");
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        has_ans=0;
        scanf("%d",&M);
        solve(M);
    }
    return 0;
}

/***************************************************
User name: 奥术大师大所大
Result: Accepted
Take time: 40ms
Take Memory: 196KB
Submit time: 2018-03-04 13:39:50
****************************************************/
