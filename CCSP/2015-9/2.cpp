#include<bits/stdc++.h>
using namespace std;
const int days=365;
const int s[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool Isleap(int y){
    if(y%400==0 || y%100 && y%4==0)return 1;
    return 0;
}

int main(){
    int y,d,res=0,i,ans;
    cin>>y>>d;
    for(i=1;i<=12;++i){
        if(i==2 && Isleap(y)){
            res+=29;
        }else{
            res+=s[i];
        }
        if(res>=d)break;
    }
    if(i==2 && Isleap(y)){
        ans=d-(res-29);
    }else ans=d-(res-s[i]);
    cout<<i<<endl<<ans;
    return 0;
}
