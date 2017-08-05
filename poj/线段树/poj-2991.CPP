#define _USE_MATH_DEFINES///使用math库中的定义
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;

const int ST_SIZE=(1<<15)-1;
const int MAX_N=10010;
const int MAX_C=10010;

int N,C;
int L[MAX_N];
int S[MAX_C],A[MAX_N];

double vx[ST_SIZE],vy[ST_SIZE]; ///各节点的向量
double ang[ST_SIZE]; ///各节点的角度

double prv[MAX_N];

///初始化线段树
void init(int k,int l,int r){
    ang[k]=vx[k]=0.0;
    if(r-l==1){
        ///叶子结点
        vy[k]=L[l];
    }else{
        int chl=(k<<1)+1,chr=(k<<1)+2;
        init(chl,l,(l+r)>>1);
        init(chr,(l+r)>>1,r);
        vy[k]=vy[chl]+vy[chr];
    }
}

///把s和s+1的角度变为a
///v是节点编号,l,r表示当前结点对应的是[l,r]区间
void update(int s,double a,int k,int l,int r){
    if(s<=l) return;
    else if(s<r){
        int chl=(k<<1)+1,chr=(k<<1)+2;
        int m=(l+r)>>1;
        update(s,a,chl,l,m);
        update(s,a,chr,m,r);
        if(s<=m) ang[k]+=a;

        double s=sin(ang[k]),c=cos(ang[k]);
        vx[k]=vx[chl]+(c*vx[chr]-s*vy[chr]);
        vy[k]=vy[chl]+(s*vx[chr]+c*vy[chr]);
    }
}

void solve(){
    init(0,0,N);
    for(int i=0;i<C;++i){
        int s=S[i];
        double a=A[i]/360.0*2*M_PI;///把角度换算成弧度
        update(s,a-prv[s],0,0,N);
        prv[s]=a;

        printf("%.2f %.2f\n",vx[0],vy[0]);
    }
}

int main(){
    while(scanf("%d%d",&N,&C)==2){
        for(int i=0;i<N;++i){
            scanf("%d",&L[i]);
            prv[i]=M_PI;///180°的弧度值
        }
        for(int i=0;i<C;++i)
            scanf("%d%d",&S[i],&A[i]);
        solve();
    }
    return 0;
}
