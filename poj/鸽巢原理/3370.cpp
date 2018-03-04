#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
long long sum[maxn];
int num;
int r[maxn];
int c,n;
int main(){
    while(~scanf("%d%d",&c,&n)&&c&&n){
        memset(r,0,sizeof(r));
        int k=0,l=1;
        sum[0]=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&num);
            sum[i]=sum[i-1]+num;

            int remainder=sum[i]%c;
            if(remainder==0){
                k=0;
                l=i;
            }else if(r[remainder]){
                k=r[remainder];
                l=i;
            }else r[remainder]=i;
        }
        printf("%d",k+1);
        for(int i=k+2;i<=l;++i){
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
