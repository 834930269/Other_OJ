#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=200;
int n,k;
int min_bucket_fill;

int main(){
    while(cin>>n>>k){
        min_bucket_fill=0x3f3f3f3f;
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            if(k%a==0)min_bucket_fill=min(k/a,min_bucket_fill);
        }
        printf("%d\n",min_bucket_fill);
    }
    return 0;
}
