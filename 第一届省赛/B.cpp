#include<bits/stdc++.h>
using namespace std;
const int maxn=310;

int N,kase=1;

int xx,yy;
char opt[10];

map<int,map<int,bool> > G;//x点集0,true为未删除,false为删除
map<int,bool>::iterator ity;
map<int,map<int,bool> >::iterator itx;

void init(){
    G.clear();
}

void add(){
    (G[xx])[yy]=true;
}

void find_(){
    itx=G.upper_bound(xx);
    while(1){
        if(itx!=G.end()){
            ity=(itx->second).upper_bound(yy);
            if(ity!=(itx->second).end() && ity->second){
                printf("%d %d\n",itx->first,ity->first);
                return;
            }
            if(ity!=(itx->second).end()){
                for(ity++;ity!=(itx->second).end();ity++){
                    if(ity->second){
                        printf("%d %d\n",itx->first,ity->first);
                        return;
                    }
                }
            }
        }else break;
        itx++;
    }
    printf("-1\n");
}

void remove_(){
    (G[xx])[yy]=false;
}

int main(){
    while(~scanf("%d",&N) && N){
        init();
        printf("Case %d:\n",kase++);
        for(int i=0;i<N;++i){
            scanf("%s %d %d",opt,&xx,&yy);
            if(opt[0]=='a'){
                add();
            }else if(opt[0]=='f'){
                find_();
            }else{
                remove_();
            }
        }
        printf("\n");
    }
    return 0;
}
