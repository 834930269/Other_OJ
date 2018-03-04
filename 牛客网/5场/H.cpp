#include<bits/stdc++.h>

#define lowbit(i) (i & (-i))

using namespace std;
typedef long long LL;
const int Nmax = 100100;
int N,Q;
LL delta[Nmax];//delta的前缀和
LL deltai[Nmax];//delta*i的前缀和
LL sum[Nmax];//原始前缀和

LL query(LL *arr,int pos){
    LL temp=0ll;
    while(pos>0){
        temp+=arr[pos];
        pos-=lowbit(pos);
    }
    return temp;
}

void update(LL *arr,int pos,int x){
    while(pos<=N){
        arr[pos]+=x;
        pos+=lowbit(pos);
    }
}

int main(){
    scanf("%d%d",&N,&Q);
    LL nw;
    char opt;
    for(int i=1;i<=N;++i){
        scanf("%lld",&nw);
        sum[i]=sum[i-1]+nw;
    }
    while(Q--){
        getchar();
        scanf("%c",&opt);
        if(opt=='C'){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            update(delta, l, x);
            update(delta, r+1, -x);
            update(deltai, l, x * l);
            update(deltai, r+1, -x * (r+1));
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            LL suml = sum[l - 1] + l * query(delta, l - 1) - query(deltai, l - 1);
            LL sumr = sum[r] + (r + 1) * query(delta, r) - query(deltai, r);
            printf("%lld\n", sumr - suml);
        }
    }
    return 0;
}
