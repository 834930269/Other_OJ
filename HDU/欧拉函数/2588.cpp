#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int euler(int n){
    int res=n,a=n;
    for(int i=2;i*i<=a;++i){
        if(a%i==0){
            ///φ(N)=N*(1-1/P1)*(1-1/P2)...其中P是素因子
            res=res/i*(i-1);//先进行除法方为了预防溢出
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        int ans=0;
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=1;i*i<=N;++i){
            if(N%i==0){
                if(i>=M)
                    ans+=euler(N/i);
                if((N/i)!=i && (N/i)>=M)
                ///如果==i且>=M的话证明i>=M,而不需要计算两次,所以排除掉
                    ans+=euler(i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
