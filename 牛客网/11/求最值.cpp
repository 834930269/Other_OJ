#include<bits/stdc++.h>
#define TREE_SIZE (1<<(20))
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=100010;
int sum_z[maxn],sum_f[maxn];
int n,num[maxn];

inline int g(int i,int j){
    register int sum=0;
    int k=min(i,j),l=max(i,j);
    sum=sum_z[n]-(sum_z[k]+sum_f[j+1]);
    return sum;
}

int main(){
    scanf("%d",&n);
    sum_z[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);

        sum_z[i]=sum_z[i-1]+num[i];
    }
    sum_f[n]=0;
    for(int i=n;i>=1;--i){
        sum_f[i]=sum_f[i+1]+num[i];
    }
    int res=1000000000;
    for(int i=2;i<=n;++i){
        int T=min(3,i);
        for(int j=1;j<T;++j){
            int reg=g(i-j,i);
            //printf("i:%d,j:%d,reg:%d\n",i,j,reg);
            int ans=j*j+reg*reg;
            res=min(res,ans);
        }
    }
    printf("%d\n",res);
    return 0;
}
