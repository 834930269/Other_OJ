#include<bits/stdc++.h>
using namespace std;

long long a[70];

void init(){
    a[1]=0;
    a[2]=1;
    a[3]=1;
    for(int i=4;i<=60;++i){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
}

int main(){
    init();
    int n;
    while(cin>>n){
        cout<<a[n]<<endl;
    }
    return 0;
}
