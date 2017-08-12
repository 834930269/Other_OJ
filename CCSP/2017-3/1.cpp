#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int N,K;
    while(~scanf("%d%d",&N,&K)){
        int ans=0,d,n=0;
        for(int i=0;i<N;++i){
            scanf("%d",&d);
            n+=d;
            if(n>=K){
                n=0;
                ans++;
            }
        }
        if(n)ans++;
        printf("%d\n",ans);
    }
    return 0;
}
