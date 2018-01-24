#include<cstdio>
#include<algorithm>
using namespace std;

long long dp[19][4];

void init(){
    dp[1][0]=4;dp[1][1]=4;
    dp[1][2]=8;dp[1][3]=8;
    for(int i=2;i<=18;++i){
        for(int j=0;j<4;++j){
            dp[i][j]=dp[i-1][j]*(2*j+1);
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        int n,d;
        scanf("%d %d",&n,&d);
        printf("%lld\n",dp[n][d]);
    }
    return 0;
}
