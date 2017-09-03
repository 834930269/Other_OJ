#include<bits/stdc++.h>
using namespace std;
struct star{
    vector<int> qb;
}star[110];

int N;
int bal[110],now[21];

void solve(){
    for(int i=1;i<=20;++i) now[i]=5;
    for(int i=0;i<N;++i){
        int ad=bal[i];
        for(int j=1;j<=20;++j){
            if(ad==0) break;
            if(now[j]>=ad){///先往可以连续中坐
                int first=(j-1)*5+1+(5-now[j]);
                now[j]-=ad;
                for(int t=first;t<first+ad;++t)
                    star[i].qb.push_back(t);
                ad-=ad;
            }
        }
        if(ad>0){///无法连续坐
            for(int j=1;j<=20;++j){
                if(ad==0) break;
                if(now[j]){
                    int cost=min(now[j],ad);
                    int first=(j-1)*5+1+(5-now[j]);
                    ad-=cost;
                    now[j]-=cost;
                    for(int t=first;t<first+cost;++t)
                        star[i].qb.push_back(t);
                }
            }
        }
    }
    for(int i=0;i<N;++i){
        int sz=star[i].qb.size();
        if(sz){
            for(int j=0;j<sz;++j){
                printf("%d ",star[i].qb[j]);
            }
            printf("\n");
        }else{
            puts("0");///?????????????????????????????????????????????????????????????????????
        }
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i) scanf("%d",&bal[i]);
    solve();
    return 0;
}
