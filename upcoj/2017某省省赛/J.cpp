#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,ca=1,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&A,&B,&C);
        printf("Case #%d: %d\n",ca++,(C-A)/B);
    }
    return 0;
}
