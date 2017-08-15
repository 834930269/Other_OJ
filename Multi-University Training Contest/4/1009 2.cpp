#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn=100010;
int n,x,nk,nm,k,m,num;
int pri[1000010],lp[10000010],s[1000010],g[1000010];
bool np[10000010];
int v[maxn],c[maxn];
int rd()
{
    int ret=0;  char gc=getchar();
    while(gc<'0'||gc>'9') gc=getchar();
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret;
}
int gcd(int a,int b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    int i,j,T;
    for(i=2;i<=10000000;i++)
    {
        if(!np[i])  pri[++num]=i,lp[i]=num;
        for(j=1;j<=num&&i*pri[j]<=10000000;j++)
        {
            np[i*pri[j]]=1,lp[i*pri[j]]=j;
            if(i%pri[j]==0) break;
        }
    }
    n=rd();
    for(i=1;i<=n;i++)    v[i]=rd();
    for(T=1;T<=4;T++)
    {
        x=v[rand()%n+1];
        for(s[0]=0,i=1;i<=n;i++)
        {
            c[i]=abs(v[i]-x);
            if(!c[i])   s[0]++;
        }
        nk=0;
        for(i=1;i<=n;i++)
        {
            int t=c[i];
            while(t&&t!=1)
            {
                int tmp=lp[t];
                s[tmp]++,g[tmp]=gcd(g[tmp],c[i]);
                if(nk<s[tmp]+s[0])   nk=s[tmp]+s[0],nm=0;
                if(nk==s[tmp]+s[0]) nm=max(nm,g[tmp]);
                while(t%pri[tmp]==0)    t/=pri[tmp];
            }
        }
        if(nk>k) k=nk,m=0;
        if(nk==k)   m=max(m,nm);
        for(i=1;i<=n;i++)
        {
            int t=c[i];
            while(t&&t!=1)
            {
                int tmp=lp[t];
                s[tmp]=g[tmp]=0;
                while(t%pri[tmp]==0)    t/=pri[tmp];
            }
        }
    }
    printf("%d %d",k,m);
    return 0;
}
