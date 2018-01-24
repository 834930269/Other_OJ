#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int main(){
    int oneday=24*60*60;
    char str1[maxn],str2[maxn];
    while(~scanf("%s %s",str1,str2)){
        int h,m,s,f;
        sscanf(str2,"%d:%d:%d",&h,&m,&s);
        scanf("%d",&f);
        int now=h*3600+m*60+s;
        int ans=0;
        if(f>=oneday-now)ans++;
        f=f-oneday+now;
        ans+=f/oneday;
        printf("%d\n",ans);
    }
    return 0;
}
