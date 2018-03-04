#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=110;
int num[maxn];
int main(){
    int n,mi=1,ma=1;
    num[0]=0;
    scanf("%d",&n);
    scanf("%d",&num[1]);
    for(int i=2;i<=n;++i){
        scanf("%d",&num[i]);
        if(num[i]<num[mi]) mi=i;
        if(num[i]>num[ma]) ma=i;
    }
    int min_id=min(mi,ma),max_id=max(mi,ma);
    int a=n-min_id,b=min_id-1,c=n-max_id,d=max_id-1;
    printf("%d\n",max(a,max(b,max(c,d))));
    return 0;
}
