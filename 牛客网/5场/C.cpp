#include<bits/stdc++.h>
using namespace std;
const int maxn=1001000;
int Next[maxn],len;
char str[maxn];

int exist[maxn];

void getNext(){
    Next[0]=-1;
    int k=-1;
    int j=0;
    while(j<len){
        if(k==-1 || str[j]==str[k]) Next[++j]=++k;
        else k=Next[k];
    }
}

void solve(){
    memset(exist,0,sizeof(exist));
    getNext();
    int bef=Next[len];
    if(bef==0){
        printf("Just a legend\n");
        return;
    }
    //忽略第一个和最后一个
    for(int i=2;i<len;++i){
        exist[Next[i]]++;
    }

    while(bef>0){
        if(exist[bef]){
            for(int i=0;i<bef;++i){
                printf("%c",str[i]);
            }
            printf("\n");
            return;
        }
        bef=Next[bef];
    }
    printf("Just a legend\n");
}

int main(){
    while(cin>>str){
        len=strlen(str);
        solve();
    }
    return 0;
}
