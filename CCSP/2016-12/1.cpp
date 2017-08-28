#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
int a[maxn],mid,N,t[maxn];

void solve(){
    mid=-1;
    sort(a,a+N);
    int mi=a[N>>1];
    if((N-t[mi])&1) printf("-1\n");
    else printf("%d\n",mi);
}
int main(){
    while(~scanf("%d",&N)){
        memset(t,0,sizeof(t));
        for(int i=0;i<N;++i) scanf("%d",&a[i]),t[a[i]]++;
        solve();
    }
    return 0;
}

