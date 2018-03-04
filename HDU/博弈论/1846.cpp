//∞Õ ≤≤©ﬁ»
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if((n)%(m+1)==0) printf("second\n");
        else printf("first\n");
    }
    return 0;
}
