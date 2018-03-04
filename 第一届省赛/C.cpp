#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
struct Query{
    int s,t;
};
int N,kase=1;
int main(){
    while(~scanf("%d",&N) && N){
        priority_queue<int,vector<int>,greater<int> > G[maxn];
        priority_queue<int,vector<int>,greater<int> > it;
        vector<Query> Q;
        for(int i=1;i<=N;++i){
            int s,t;
            scanf("%d%d",&s,&t);
            G[s].push(t);
            Q.push_back((Query){s,t});
        }
        printf("Case %d:\n",kase++);
        for(int i=0;i<Q.size();++i){
            int s=Q[i].s,t=Q[i].t;
            bool has_ans=false;
            for(int j=s+1;j<=309 && !has_ans;++j){
                it=G[j];
                while(!it.empty()){
                    int nw=it.top();it.pop();
                    if(nw>t){
                        has_ans=true;
                        printf("%d %d\n",j,nw);
                        break;
                    }
                }
            }
            if(!has_ans){
                printf("-1 -1\n");
            }
        }
        printf("\n");
    }
    return 0;
}
