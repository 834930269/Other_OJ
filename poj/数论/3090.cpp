#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1000+100;
int phi[maxn];
int Farey[maxn];


inline void phi_table(){
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<maxn;++i){
        if(!phi[i]){
            for(int j=i;j<maxn;j+=i){
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
    int n,kase=1,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d %d %d\n",kase++,n,Farey[n]*2+3);
    }
    return 0;
}
