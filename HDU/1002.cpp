#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
char num1[maxn],num2[maxn];
int sum[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;++kase){
        scanf("%s %s",num1,num2);
        fill(sum,sum+maxn,0);
        int len=strlen(num1),len2=strlen(num2);
        for(int i=len-1,t=0;i>=0;--i,++t)
            sum[t]=num1[i]-'0';
        for(int i=len2-1,t=0;i>=0;--i,++t)
            sum[t]+=(num2[i]-'0');
        int q=0,p=max(len,len2);
        while(sum[q] || q<p){
            sum[q+1]+=(sum[q]/10);
            sum[q]=sum[q]%10;
            q++;
        }
        printf("Case %d:\n%s + %s = ",kase,num1,num2);
        for(int i=q-1;i>=0;--i)
            printf("%d",sum[i]);
        printf("\n");
        if(kase!=T) printf("\n");
    }
    return 0;
}
