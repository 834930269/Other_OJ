///HDU 6047
#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+50;
const int mod=1e9+7;
int N;
int a[maxn],b[maxn],maxa[maxn];

int main(){
    while(~scanf("%d",&N)&&N){
        for(int i=1;i<=N;++i){
            int aa;
            scanf("%d",&aa);
            a[i]=aa-i;
        }
        maxa[N]=a[N];
        for(int i=N-1;i>=1;--i) maxa[i]=max(maxa[i+1],a[i]);
        for(int i=1;i<=N;++i) scanf("%d",&b[i]);
        sort(b+1,b+1+N);
        long long ans=0;
        ans=(ans+maxa[b[1]])%mod;
        int t=maxa[b[1]]-N-1;
        for(int i=2;i<=N;++i){
            maxa[b[i]]=max(maxa[b[i]],t);
            ans=(ans+maxa[b[i]])%mod;
            t=max(t,maxa[b[i]]-N-1);
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
