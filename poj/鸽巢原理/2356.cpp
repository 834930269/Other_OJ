//问从N个数中选取多少个数,使得这些数的和%N==0
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000+10;
int num[maxn],sum[maxn];
int r[maxn];
int main(){
    int N,ans=0,k=0,l=1;
    memset(r,-1,sizeof(r));
    scanf("%d",&N);
    sum[0]=0;

    for(int i=1;i<=N;++i){
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];

        int remainder=sum[i]%N;
        if(remainder==0){
            ans=i;
            k=0;
            l=i;
        }else if(r[remainder]!=-1){
            ans=i-r[remainder];
            k=r[remainder];
            l=i;
        }else r[remainder]=i;
    }
    printf("%d\n",ans);
    for(int i=k+1;i<=l;++i){
        printf("%d\n",num[i]);
    }
    return 0;
}
