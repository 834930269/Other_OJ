#include<bits/stdc++.h>
using namespace std;
int mp[500],T;
char str[100];
int ind[20][8]={
        {1,1,1,0,1,1,1},
        {0,0,1,0,0,1,0},
        {1,0,1,1,1,0,1},
        {1,0,1,1,0,1,1},
        {0,1,1,1,0,1,0},
        {1,1,0,1,0,1,1},
        {1,1,0,1,1,1,1},
        {1,0,1,0,0,1,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1},
    };
int reg[10];
int solve[10][20]={{1,6,13,18},{0,5,12,17},{3,8,15,20},{1,6,13,18},{0,5,12,17},{3,8,15,20},{1,6,13,18}};
void init(){
    memset(mp,0,sizeof(mp));
    for(int i=0;i<10;++i){
        int ans=0;
        for(int j=0;j<7;++j){
            if(ind[i][j]==1) ans|=(1<<j);
        }
        //printf("%d: %d\n",i,ans);
        mp[ans]=i;
    }
}

void deal(int k){
    for(int i=0;i<4;++i){
        if(str[solve[k][i]]=='X') reg[i]|=(1<<k);
    }
}

int main(){
    init();
    scanf("%d%*c",&T);
    while(T--){
        fill(reg,reg+7,0);
        for(int i=0;i<7;++i){
            gets(str);
            deal(i);
        }
        //for(int i=0;i<4;++i) printf("%d\n",reg[i]);
        printf("%d%d:%d%d\n",mp[reg[0]],mp[reg[1]],mp[reg[2]],mp[reg[3]]);
    }
    return 0;
}
