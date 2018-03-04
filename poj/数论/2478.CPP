#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1000000+100;
LL phi[maxn];
LL Farey[maxn];


inline void phi_table(){
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(LL i=2;i<maxn;++i){
        if(!phi[i]){
            for(LL j=i;j<maxn;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]-phi[j]/i;
            }
        }
    }
}

inline void init(){
    phi_table();
    memset(Farey,0,sizeof(Farey));
    for(int i=2;i<maxn;++i){
        Farey[i]=Farey[i-1]+phi[i];
    }
}

int main(){
    init();
    int n;
    while(~scanf("%d",&n)&&n){
        printf("%lld\n",Farey[n]);
    }
    return 0;
}
