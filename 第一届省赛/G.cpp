#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100100;
int Dist[maxn],N;
int main(){
    while(~scanf("%d",&N) && N){
        for(int i=0;i<N;++i){
            scanf("%d",&Dist[i]);
        }
        sort(Dist,Dist+N);
        LL ans=0ll;
        for(int i=1;i<N;++i){
            ans+=((Dist[i]-Dist[i-1])<<1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
