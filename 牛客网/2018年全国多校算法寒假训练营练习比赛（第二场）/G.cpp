#include<bits/stdc++.h>
using namespace std;

const int maxn=10;
int dp[maxn][10];
int d[maxn],N,M;

//dp[i][j]表示i位数,首位是j的数字有多少符合要求的
void init(){
    dp[0][0]=1;
    for(int i=1;i<=7;++i){
        //，枚举首位
        for(int j=0;j<=9;++j){
            //枚举第二位
            for(int k=0;k<=9;++k){
                if(j!=4&&!(j==3&&k==8))
                    dp[i][j]+=dp[i-1][k];
            }
        }
    }
}

int solve(int num){
    int ans=0,len=0;
    while(num){
        d[++len]=num%10;
        num/=10;
    }

    d[len+1]=0;
    for(int i=len;i>=1;--i){
        for(int j=0;j<d[i];++j){
            if(d[i+1]!=3 || j!=8)
                ans+=dp[i][j];
        }

        if(d[i]==4||(d[i+1]==3&&d[i]==8))
            break;
    }
    return ans;
}

int main(){
    init();
    while(scanf("%d%d", &N, &M) == 2){
        if (N == 0 && M== 0) break;
        printf("%d\n",(M-N+1)-(solve(M + 1) - solve(N)));
    }
    return 0;
}
