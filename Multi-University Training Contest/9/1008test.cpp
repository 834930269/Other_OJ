#include<bits/stdc++.h>
using namespace std;
int t[5]={3,7,6,9,10};
vector<int> ans;
int main(){
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
     for(int i=0;i<5;++i) ans.push_back(t[i]);
     for(int i=0;i<5;++i){
        for(int j=i+1;j<5;++j){
            ans.push_back(t[i]+t[j]);
        }
     }
     printf("%d\n",ans.size());
     for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
    return 0;
}
