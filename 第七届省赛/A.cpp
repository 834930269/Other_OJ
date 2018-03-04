#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,A,B;
    while(~scanf("%d",&T)){
        for(int i=0;i<T;++i){
            cin>>A>>B;
            if(A%B){
                cout<<(A/B)+1<<endl;
            }else{
                cout<<(A/B)<<endl;
            }
        }
    }
    return 0;
}
