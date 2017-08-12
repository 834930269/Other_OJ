#include<bits/stdc++.h>
using namespace std;

int N,M;
int I,J;

list<int> li;

int main(){
    while(~scanf("%d%d",&N,&M)){
        li.clear();
        for(int i=1;i<=N;++i){
            li.push_back(i);
        }
        for(int i=1;i<=M;++i){
            scanf("%d%d",&I,&J);
            if(J==0)continue;
            list<int>::iterator it,it2;
            for(it=li.begin();*it!=I;it++){}
            it2=it;
            int flag=J>0?1:-1;
            J=abs(J)+(flag>0?1:0);
            while(J){
                J--;
                flag>0?it++:it--;
            }
            li.insert(it,I);
            li.erase(it2);
        }
        list<int>::iterator it;
        it=li.begin();
        printf("%d",*it);
        it++;
        for(;it!=li.end();it++){
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}
