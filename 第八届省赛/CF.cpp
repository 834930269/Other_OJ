#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;

struct pro{
    int a,d,c;
    //按单位时间内减少分值排序
    bool operator <(const pro &pt)const{
        return 1.0*d/c>(1.0*pt.d/pt.c);
    }
};

int n,T;
pro p[maxn];
int dp[5010];
int main(){
    while(~scanf("%d%d",&n,&T)){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i){
            scanf("%d",&p[i].a);
        }
        for(int i=0;i<n;++i){
            scanf("%d",&p[i].d);
        }
        for(int i=0;i<n;++i){
            scanf("%d",&p[i].c);
        }
        sort(p,p+n);
        int mx=-1;
        for(int i=0;i<n;++i){
            for(int j=T;j>=0;--j){
                if(j>=p[i].c){
                    dp[j]=max(dp[j],dp[j-p[i].c]+p[i].a-j*p[i].d);
                }
                mx=max(mx,dp[j]);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
