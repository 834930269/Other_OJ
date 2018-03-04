#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
set<int> st;
int FB[maxn];
int n;
inline void init(){
    FB[1]=1ll;FB[0]=1ll;
    int i;
    for(i=2;FB[i-1]<=1e9+7;++i){
        FB[i]=FB[i-1]+FB[i-2];
        st.insert(FB[i]);
    }
}

int main(){
    init();
    while(~scanf("%d",&n)){
        if(st.find(n)!=st.end()){
            cout<<"Sha"<<endl;
        }else{
            cout<<"Xian"<<endl;
        }
    }
    return 0;
}
