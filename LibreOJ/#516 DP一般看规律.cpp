#include<bits/stdc++.h>
using namespace std;
int ans,n,m,num,x,y;
map<int,set<int> > mp;

void insert_update(int q,int index){
    set<int> &r=mp[q];
    set<int>::iterator it=r.lower_bound(index);
    if(it!=r.end()) ans=min(ans,*it-index);///右边相邻第一个
    if(it!=r.begin()) it--,ans=min(ans,index-*it);///左边相邻第一个
    r.insert(index);
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        ans=2147483647;mp.clear();
        for(int i=0;i<n;++i){
            scanf("%d",&num);
            insert_update(num,i);
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&x,&y);
            if(x==y){printf("%d\n",ans);continue;}
            set<int> &r=mp[x],&t=mp[y];
            if(r.size()>t.size())swap(r,t);
            for(set<int>::iterator si=r.begin();si!=r.end();si++)
                insert_update(y,*si);
            r.clear();
            printf("%d\n",ans);
        }
    }
    return 0;
}
