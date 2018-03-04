#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000+10;
int a,b,tot=0;

bool valid[maxn];
int prime[maxn];
void init(int n,int ans[maxn]){
    memset(valid,true,sizeof(valid));
    for(int i=2;i<=n;++i){
        if(valid[i]){
            tot++;
            ans[tot]=i;
        }
        for(int j=1;((j<=tot) && (i*ans[j]<=n));++j){
            valid[i*ans[j]]=false;
            if(i%ans[j]==0) break;
        }
    }
}

int query(int len,int key){
    int left=1;
    int right=len;
    int mid;
    while(left<=right){
        mid=(left+right)>>1;
        if(key<prime[mid]){
            right=mid-1;
        }else if(key>prime[mid]){
            left=mid+1;
        }else return mid;
    }
    return -1;
}

bool check(int n){
    if((n/10)==0) return true;
    int str[20];
    int len=0,l=n;
    for(;l>0;){
        ++len;
        str[len]=l%10;
        l/=10;
    }
    for(int i=1;i<=len;++i){
        if(str[i]!=str[len-i+1]) return false;
    }
    return true;
}

int main(){
    init(10000000,prime);
    while(~scanf("%d %d",&a,&b)){
        int id=query(tot,a);
        for(int i=id;prime[i]<=b && prime[i];++i){
            if(check(prime[i])){
                printf("%d\n",prime[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
