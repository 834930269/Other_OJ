#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
LL arr[10][10][10];
LL a,b;
int main(){
    ///2016=2*2*2*2*2*3*3*7

    while(~scanf("%lld%lld",&a,&b)){
        memset(arr,0,sizeof(arr));
        for(int i=0;i<6;++i)
            for(int j=0;j<3;++j)
                for(int t=0;t<2;++t)
                    arr[i][j][t]=a/(int)(pow(2,i)*pow(3,j)*pow(7,t));
        LL ans=0;
        for(int i=0;i<6;++i)
            for(int j=0;j<3;++j)
                for(int t=0;t<2;++t)
                    ans+=(arr[i][j][t]-arr[i+1][j][t]-arr[i][j+1][t]-arr[i][j][t+1]+arr[i+1][j+1][t]+arr[i+1][j][t+1]+arr[i][j+1][t+1]-arr[i+1][j+1][t+1])*(b/(int)(pow(2,5-i)*pow(3,2-j)*pow(7,1-t)));
        printf("%lld\n",ans);
    }
    return 0;
}
