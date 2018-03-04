#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,m;
int num[maxn];

void solve1(){
    int l,r,x,y;
    scanf("%d%d%d%d",&l,&r,&x,&y);
    for(int i=l;i<=r;++i){
        if(num[i]==x)num[i]=y;
    }
}

void solve2(){
    int l,r,k;
    scanf("%d%d%d",&l,&r,&k);
    int copy[maxn];
    for(int i=l;i<=r;++i){
        copy[i]=num[i];
    }
    sort(copy+l,copy+r+1);
    printf("%d\n",copy[l+k-1]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
    }
    int query;
    for(int i=0;i<m;++i){
        scanf("%d",&query);
        if(query==1) solve1();
        else solve2();
    }

    return 0;
}
