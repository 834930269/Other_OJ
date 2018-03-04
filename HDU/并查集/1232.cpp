#include<bits/stdc++.h>

using namespace std;

struct DisjointSet{
    vector<int> father,rank;
    int Num;
    DisjointSet(int n):father(n),rank(n),Num(n){
        for(int i=1;i<n;++i){
            father[i]=i;
        }
    }

    int find(int v){
        return father[v]=father[v]==v?v:find(father[v]);
    }

    void merge(int x,int y){
        int a=find(x),b=find(y);
        if(rank[a]<rank[b]){
            father[a]=b;
        }else{
            father[b]=a;
            if(rank[a]==rank[b]){
                ++rank[a];
            }
        }
    }

    int getCnum(){
        int ans=0;
        for(int i=1;i<Num;++i){
            if(father[i]==i) ans++;
        }
        return ans-1;
    }
};

int main(){
    int m,n;

    while(scanf("%d",&n) && n){
        DisjointSet ds(n+1);
        int s,t;
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            scanf("%d %d",&s,&t);
            ds.merge(s,t);
        }
        printf("%d\n",ds.getCnum());
    }
    return 0;
}
