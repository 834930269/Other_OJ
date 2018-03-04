#include<bits/stdc++.h>
#define lowbit(i) (i&(-i))
using namespace std;
typedef long long LL;
const int maxn=100100;
LL Tree[maxn];

void add(int x,int value){
    for(int i=x;i<=maxn;i+=lowbit(i)){
        Tree[i]+=value;
    }
}

LL get(int x){
    LL sum=0ll;
    for(int i=x;i;i-=lowbit(i)){
        sum+=Tree[i];
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        LL q;
        scanf("%lld",&q);
        add(i,q);
    }
    for(int i=0;i<m;++i){
        int ck;
        scanf("%d",&ck);
        if(ck==1){
            int x,k;
            scanf("%d%d",&x,&k);
            add(x,k);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",get(r)-get(l-1));
        }
    }
    return 0;
}
