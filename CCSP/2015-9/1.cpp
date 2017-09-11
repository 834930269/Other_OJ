#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,C,cnt=0,pre;
    cin>>T;
    cin>>C;pre=C;cnt++;T--;
    while(T--){
        cin>>C;
        if(pre!=C){
            pre=C,cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
