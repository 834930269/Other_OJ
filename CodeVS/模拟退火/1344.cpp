#define F(i,n) for(int i=0;i<n;++i)
#define Fi(i,n) for(int i=1;i<=n;++i)
#include<bits/stdc++.h>
using namespace std;
const int maxn=21;
int n;
double x[maxn],y[maxn];
double dist[maxn][maxn];
struct Path{
    int path[maxn];
    Path(){
        F(i,n) path[i]=i;
    }
    Path(const Path& p){
        memcpy(path,p.path,sizeof(path));
        swap(path[rand()%n],path[rand()%n]);
    }
    double dist(){
        double ans=0;
        for(int i=1;i<n;++i){
            ///解决重名的办法
            ans+= ::dist[path[i-1]][path[i]];
        }
        return ans;
    }
};

bool accept(double delta,double temper){
    if(delta<=0) return true;
    return rand()<=exp((-delta)/temper)*RAND_MAX;
}

double solve(){
    const double max_temper=10000;
    const double dec=0.999;
    double temp=max_temper;
    Path p;
    while(temp>0.01){
        Path p2(p);
        if(accept(p2.dist()-p.dist(),temp)) p=p2;
        temp*=dec;
    }
    return p.dist();
}

int main(){
    srand(19260817U);
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%lf%lf",x+i,y+i);
    }
    for(int i=0;i<n;++i){
        dist[i][i]=0;
        for(int j=i+1;j<n;++j){
            dist[i][j]=dist[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
        }
    }
    double ans=0x3f3f3f3f;
    int T=155;
    while(T--){
        ans=min(ans,solve());
    }
    printf("%.2lf",ans);
    return 0;
}
