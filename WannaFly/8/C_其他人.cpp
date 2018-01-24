//题目连接:https://www.nowcoder.com/acm/contest/57/C
#include<bits/stdc++.h>
#define N 505
using namespace std;
double a[11][N],F[N][105];int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        scanf("%lf",&a[i][j]);
    for (int i=m-1;i>=0;i--)
      for (int S=0;S<(1<<n);S++){
          F[i][S]=F[i+1][S];
          for (int j=0;j<n;j++)
            if ((S>>j)&1^1){
                double now=0;
                for (int k=1;k+i<=m;k++)
                  now+=(F[i+k][S|(1<<j)]+1)*a[j+1][k];
                F[i][S]=max(F[i][S],now);
            }
        }
    printf("%.5f\n",F[0][0]);
}
