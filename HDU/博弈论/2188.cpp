//∞Õ ≤≤©ﬁ»
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,n,m;
    while(~scanf("%d",&T)){
        while(T--){
            scanf("%d%d",&n,&m);
            if((n)%(m+1)==0) printf("Rabbit\n");
            else printf("Grass\n");
        }
    }
    return 0;
}
