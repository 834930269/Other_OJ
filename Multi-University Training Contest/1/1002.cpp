#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7;
struct star{
    int reg[100005];
    bool vi;
    int c;
    bool operator < (const star &A)const{
        for(int i=maxn-1;i>=0;--i){
            if(reg[i]>A.reg[i]) return 1;
            else if(reg[i]<A.reg[i]) return 0;
            else continue;
        }
    }
}ch[30];
char str[100005];
int Hash[30];///字符-权值映射
long long ans,fac[100005];
inline void init(){
    for(int i=0;i<27;++i){
        memset(ch[i].reg,0,sizeof(ch[i].reg));
        ch[i].vi=true;
        ch[i].c=0;
    }
    ans=0;
}
int main(){
    int n,len,p,kase=0;
    fac[0]=1;///预先处理26^i;
    for(int i=1;i<maxn;++i)
        fac[i]=fac[i-1]*26%mod;
    while(~scanf("%d",&n)){
        init();
        for(int i=0;i<n;++i){
            scanf("%s",str);
            len=strlen(str);
            for(int j=0;j<len;++j){
                p=str[j]-'a';
                ch[p].reg[len-j-1]++;
            }
            if(len>1)
                ch[str[0]-'a'].vi=false;
        }
        for(int i=0;i<26;++i){
            for(int j=0;j<maxn;++j){
                if(ch[i].reg[j]>=26){
                    ch[i].reg[j+1]+=ch[i].reg[j]/26;
                    ch[i].reg[j]%=26;
                }
            }
            ch[i].c=i;
        }
        sort(ch,ch+26);
        for(int i=0;i<26;++i)
            Hash[ch[i].c]=26-i-1;
        for(int i=25;i>=0;--i){///从最小的开始判断是否可以为0
            if(ch[i].vi){
                for(int j=25;j>i;--j)
                    Hash[ch[j].c]=Hash[ch[j-1].c];
                Hash[ch[i].c]=0;
                break;
            }
        }
        for(int i=0;i<26;++i){
            for(int j=0;j<maxn;++j){
                ans=(ans+fac[j]*ch[i].reg[j]*Hash[ch[i].c]%mod)%mod;
            }
        }
        printf("Case #%d: %lld\n",++kase,ans);
    }
    return 0;
}
