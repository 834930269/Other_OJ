#include<bits/stdc++.h>
using namespace std;
int N,T;
int main(){
    while(~scanf("%d",&T)&&T){
        int cnt=0;
        for(int i=0;i<T;++i){
            scanf("%d",&N);
            if(N<=35)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
