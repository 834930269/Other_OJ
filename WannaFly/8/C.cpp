//Wrong
#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;
double p;

int n,m;
double sum_i[maxn];
int main(){
    while(~scanf("%d%d",&n,&m)){
        double sum_a=0.0;
        memset(sum_i,0.0,sizeof(sum_i));
        for(int i=0;i<n;++i){
            double si=0.0;
            for(int j=0;j<m;++j){
                scanf("%lf",&p);
                si+=(p*(j+1));
            }
            sum_i[i]=si;
        }
        sort(sum_i,sum_i+n);
        for(int i=0;i<n;++i){
            sum_a+=sum_i[i];
            if(sum_a>=m){
                break;
            }
        }
        printf("%.5lf\n",sum_a/m);
    }
    return 0;
}
