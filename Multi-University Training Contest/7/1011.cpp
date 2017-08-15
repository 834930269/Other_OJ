#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000+10;
int T;
int dat[maxn],sz=0;

void init(int n){
    bool flag=true;///flag=1,flag=2(false)
    dat[1]=1;dat[2]=2;
    for(int i=1;sz<n;++i){
        int ct=dat[i];
        if(flag){
            for(int t=0;t<ct;t++)
                dat[++sz]=1;
            flag=false;
        }else{
            for(int t=0;t<ct;t++)
                dat[++sz]=2;
            flag=true;
        }
    }
}

int main(){
    scanf("%d",&T);
    init(10000001);
    while(T--){
        int x;
        scanf("%d",&x);
        printf("%d\n",dat[x]);
    }
    return 0;
}
