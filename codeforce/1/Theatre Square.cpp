#include<cstdio>
#include<iostream>
#include<algorithm>
#define EPS 1e-9
using namespace std;

int n,m,a;

long long up_bound(double s){
    long long ans=s;
    if(s-ans>EPS){
        ans++;
    }
    return ans;
}

int main(){
    while(scanf("%d %d %d",&n,&m,&a)!=EOF){
        long long row = up_bound(1.0*m/a);
        long long column = up_bound(1.0*n/a);
        long long ans=row*column;
        printf("%lld\n",ans);
    }
    return 0;
}
