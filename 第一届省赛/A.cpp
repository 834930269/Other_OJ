#include<bits/stdc++.h>
using namespace std;
const int CHARSET=10,BASE='0',MAX_NODE=10100;
struct Trie{
    int tot,root,child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    bool has_prefix;
    bool is_root[MAX_NODE][CHARSET];
    Trie(){
        //printf("New Trie\n");
        memset(child[1],0,sizeof(child[1]));
        memset(is_root,false,sizeof(is_root));
        flag[1]=false;
        has_prefix=false;
        root=tot=1;
    }
    void insert(const char *str){
        int *cur=&root;
        char last_char;
        for(const char *p=str;*p;++p){
            cur=&child[*cur][*p-BASE];
            last_char=*p;
            if(is_root[*cur][last_char])has_prefix=true;
            if(*cur==0){
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=false;
            }
        }
        flag[*cur]=true;
        is_root[*cur][last_char]=true;
    }

};
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        Trie te;
        char str[10000];
        for(int i=0;i<n;++i){
            scanf("%s",str);
            if(!te.has_prefix){
                te.insert(str);
            }
        }
        if(te.has_prefix){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
