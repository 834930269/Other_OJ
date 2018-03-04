#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
int m[maxn];

void init(){
    m[0]=7,m[1]=11;
    for(int i=2;i<=1000000;++i){
        m[i]=((m[i-1]%3)+(m[i-2]%3))%3;
    }
}

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        printf("%s\n",(!m[n])?"yes":"no");
    }
    return 0;
}
