#include<bits/stdc++.h>
using namespace std;
const int MAX_N=110;
int N,K;
int candy[MAX_N];

void solve(){
    int A=0,B=0,dy=-1;
    for(int i=0;i<N;++i){
        A+=candy[i];
        B+=min(8,A);
        A-=min(8,A);
        if(B>=K){
            dy=i+1;
            break;
        }
    }
    printf("%d\n",dy);
}
int main(){
    while(~scanf("%d%d",&N,&K)){
        for(int i=0;i<N;++i) scanf("%d",&candy[i]);
        solve();
    }
    return 0;
}
