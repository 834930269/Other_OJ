#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(cin>>n){
        while(n/10){
            int nn=0;
            while(n>0){
                nn+=(n%10);
                n/=10;
            }
            n=nn;
        }
        cout<<n<<endl;
    }
    return 0;
}
