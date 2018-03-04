#include<bits/stdc++.h>
using namespace std;
int main(){
    int K;
    while(~scanf("%d",&K)){
        if(K==0) break;
        int ans=0;
        while(K--){
            int a;
            scanf("%d",&a);
            ans^=a;
        }
        if(ans==0)puts("Grass Win!");
        else puts("Rabbit Win!");
    }
    return 0;
}
