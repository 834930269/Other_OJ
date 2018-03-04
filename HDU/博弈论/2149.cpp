//∞Õ ≤≤©ﬁ»
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n%(m+1)==0) printf("none\n");
        else{
            int next=0;
            while(1){
                next++;
                if((n-next)%(m+1)==0){
                    printf("%d",next);
                    break;
                }
            }
            while(next<m){
                next++;
                if((n-next)%(m+1)==0 || next>=n){
                    printf(" %d",next);
                }else{
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
