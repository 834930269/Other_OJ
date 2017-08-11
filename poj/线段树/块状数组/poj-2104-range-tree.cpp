#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
///线段树仿归并排序法
///归并树
const int ST_SIZE=(1<<18)-1;
const int MAX_N=100000+10;
const int MAX_M=5000+10;
///输入
int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];

int nums[MAX_N];///对A排序之后的结果
vector<int> dat[ST_SIZE];///线段树的数据

///构建线段树
///k是节点的编号,和区间[l,r)对应
void build(int k,int l,int r){
    if(r-l==1){
        dat[k].push_back(A[l]);
    }else{
        int lch=(k<<1)+1,rch=(k<<1)+2;
        build(lch,l,(l+r)>>1);
        build(rch,(l+r)>>1,r);
        ///提前分配空间才不会出错
        dat[k].resize(r-l);
        ///利用STL的merge函数把两个儿子的数列合并成一个有序数列
        merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),dat[k].begin());
    }
}

///计算[a,b)中不超过x的数的个数
int query(int a,int b,int x,int k,int l,int r){
    if(l>=b || r<=a){
        ///完全不相交
        return 0;
    }else if(a<=l&&r<=b){
        ///完全包含在里面
        return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
    }else{
        ///递归计算儿子节点
        int lc=query(a,b,x,(k<<1)+1,l,(l+r)>>1);
        int rc=query(a,b,x,(k<<1)+2,(l+r)>>1,r);
        return lc+rc;
    }
}

void solve(){
    for(int i=0;i<N;++i){
        nums[i]=A[i];
    }
    sort(nums,nums+N);
    build(0,0,N);
    for(int i=0;i<M;++i){
        int l=I[i],r=J[i],k=K[i];
        int lb=-1,ub=N-1;
        while(ub-lb>1){
            int md=(ub+lb)>>1;
            int c=query(l,r,nums[md],0,0,N);
            if(c>=k)ub=md;
            else lb=md;
        }
        printf("%d\n",nums[ub]);
    }
}

int main(){
    while(~scanf("%d%d",&N,&M)){
        for(int i=0;i<N;++i){
            scanf("%d",&A[i]);
        }
        for(int i=0;i<M;++i){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            l--;
            I[i]=l,J[i]=r,K[i]=k;
        }
        solve();
        for (int i = 0; i < ST_SIZE; i++) {
            dat[i].clear();
        }
    }
    return 0;
}
