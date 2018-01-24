#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int n,pos,l,r;
int main(){
    while(cin>>n>>pos>>l>>r){
        if(l==1&&r==n){printf("0\n");continue;}
        int ans=0;
        ans=abs(min(abs(pos-l),abs(pos-r))+2+r-l);
        if(l==1)ans=abs(pos-r)+1;
        if(r==n)ans=abs(pos-l)+1;
        printf("%d\n",ans);
    }
    return 0;
}
