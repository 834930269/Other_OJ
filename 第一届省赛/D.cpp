#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=2000;
int N,M,KASE=1;
int arr[maxn];
vector<int> first;
int main(){
    while(~scanf("%d%d",&N,&M) && N+M){
        first.clear();
        int ans=0;
        for(int i=0;i<N;++i) scanf("%d",&arr[i]);
        for(int i=0;i<N;++i){
            for(int j=i;j<N;++j){
                first.push_back(-(arr[i]+arr[j]));
            }
        }
        sort(first.begin(),first.end());
        for(int i=0;i<first.size();++i){
            int need=M+first[i];
            if(need<=0) continue;
            else{
                int id=lower_bound(first.begin(),first.end(),-need)-first.begin();
                int nw=-(first[i]+first[id]);
                if(nw<=M) ans=max(ans,nw);
            }
            if(ans==M)break;
        }
        printf("Case %d: %d\n\n",KASE++,ans);
    }
    return 0;
}
