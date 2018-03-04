#include<bits/stdc++.h>
using namespace std;

int solve(int N){
    int ans=0;
    for(int i=1;i<N;++i){
        for(int j=i;j<N-i;++j){
            int k=N-i-j;
            if((i^j^k)==0) ans++;
        }
    }
    return ans;
}

int main(){
    for(int i=1;i<=200;++i){
        printf("%d: %d\n",i,solve(i)/3);
    }
    return 0;
}
