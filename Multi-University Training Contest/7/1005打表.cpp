#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;

bool prime[1000000001];

int phi(int n){
    int i,rea=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            rea=rea-rea/i;
            while(n%i==0)  n/=i;
        }
    }
    if(n>1)
        rea=rea-rea/n;
    return rea;
}



int main(){
        freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T,j=1;
    for(;j<100;++j){
        memset(prime,true,sizeof(prime));
        int K,cnt=0;
        //scanf("%d",&K);
        for(int i=1;i<=j;++i){
            if(prime[j%i]){
                cnt++;
                prime[j%i]=false;
            }
        }
        printf("%d,",cnt+1);
    }
    return 0;
}
