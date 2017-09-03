#include<bits/stdc++.h>
using namespace std;
int num[100000];
int N;
int main(){
    scanf("%d",&N);
    int maxn=0;
    for(int i=0;i<N;++i){
        scanf("%d",&num[i]);
        if(i>=1) maxn=max(maxn,abs(num[i]-num[i-1]));
    }
    printf("%d\n",maxn);
    return 0;
}
