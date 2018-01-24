#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std;
const int MAXN=100;
int N;
char Q[MAXN];
//10进制转26进制
void solveToAlpha(){
    stack<char> ans;
    int a,num;
    sscanf(Q,"R%dC%d",&a,&num);
    int i;
    for(i=0;num>0;i++){
        char c=(num-1)%26+'A';
        ans.push(c);
        num=(num-1)/26;
    }
    while(!ans.empty()){
        printf("%c",ans.top());
        ans.pop();
    }
    printf("%d\n",a);
}
//26进制转10进制
void solveToNum(){
    int a;
    char b[MAXN];
    sscanf(Q,"%[A-Z]%d",b,&a);
    long long ans=0;
    int len=strlen(b);
    for(int i=0;i<len;++i){
        ans*=26;
        ans=ans+b[i]-'A'+1;
    }
    printf("R%dC%lld\n",a,ans);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%s",Q);
        int a,b;
        //sscanf()
        if(sscanf(Q,"R%dC%d",&a,&b)==2){
            solveToAlpha();
        }else{
            solveToNum();
        }
    }
    return 0;
}
