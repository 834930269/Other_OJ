#include<bits/stdc++.h>
using namespace std;
int G[15][10];
int kk[4][4],max_row=0;
int T;
int solve(){
    for(int i=0;i<15-max_row;++i){
        for(int j=0;j<=max_row;++j){
            for(int t=0;t<4;++t){
                if(G[i+j][T+t]&&kk[j][t])return i;
            }
        }
    }
    return 15-max_row;
}
int main(){
    for(int i=0;i<15;++i)
    for(int j=0;j<10;++j){
        scanf("%d",&G[i][j]);
    }

    for(int i=0;i<4;++i)
    for(int j=0;j<4;++j){
        scanf("%d",&kk[i][j]);
        if(kk[i][j])max_row=max(max_row,i);
    }
    scanf("%d",&T);T-=1;
    int ind=solve()-1;
    for(int i=0;i<=max_row;++i){
        for(int j=0;j<4;++j){
            G[ind+i][T+j]+=kk[i][j];
        }
    }
    for(int i=0;i<15;++i){
        printf("%d",G[i][0]);
        for(int j=1;j<10;++j){
            printf(" %d",G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
