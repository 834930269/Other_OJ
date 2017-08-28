#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[10][10];
void init()
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=7;i++)
    {
        for(int j=0;j<10;j++)//枚举第i位可能出现的数
        {
            for(int k=0;k<10;k++)//枚举第i-1位可能出现的数
            {
                if(j!=4)
                    dp[i][j]  += dp[i-1][k];
            }
        }
    }
}
int solve(int n)
{
    init();
    int digit[10];
    int len = 0;
    while(n>0)
    {
        digit[++len] = n%10;
        n/=10;
    }
    digit[len+1]=0;
    int ans = 0;
    for(int i=len;i;i--)
    {
        for(int j=0;j<digit[i];j++)
        {
            if(j!=4)
                ans+=dp[i][j];
        }
        if(digit[i]==4)
            break;
    }
    return  ans;
}
int main()
{
    int N,T,ca=1;
    cin>>T;
    while(T--)
    {
        cin>>N;
        printf("Case #%d: %d\n",ca++,solve(N));
    }
    return 0;
}
