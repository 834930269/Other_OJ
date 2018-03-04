#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int numpy[maxn],n,d;

int main(){
    cin>>n>>d;
    int num;
    for(int i=0;i<n;++i){
        cin>>num;
        numpy[num]++;
    }
    int real=110;
    for(int i=1;i<=100;++i){
        int ans=0;
        for(int j=0;j<=d;++j){
            if(j==0){
                ans+=numpy[i];
            }else{
                int up=i+j;
                if(up<=100) ans+=numpy[up];
            }
        }
        real=min(real,n-ans);
    }
    cout<<real<<endl;
    return 0;
}
