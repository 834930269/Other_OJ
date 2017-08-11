///可能是poj更新数据了.二分被卡了- -TLE
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int B=1000;///桶的大小
const int MAX_N=100000+10;
const int MAX_M=5000+10;
///输入
int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];

int nums[MAX_N]; ///对A排序后的结果
vector<int> bucket[MAX_N / B]; ///每个桶排序之后的结果

void solve(int l,int r,int k){
    ///求[l,r)区间中第k个数
    int lb=-1,ub=N-1;
    while(ub-lb>1){
        int md=(lb+ub)>>1;
        int x=nums[md];
        int tl=l,tr=r,c=0;

        ///区间两端多出的部分
        while(tl<tr && tl % B !=0) if(A[tl++]<=x) c++;
        while(tl<tr && tr % B !=0) if(A[--tr]<=x) c++;

        ///对每一个桶进行计算
        while(tl<tr){
            int b=tl/B;
            c+=upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
            tl+=B;
        }
        if(c>=k) ub=md;
        else lb=md;
    }
    printf("%d\n",nums[ub]);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i){
            scanf("%d",&A[i]);
            bucket[i/B].push_back(A[i]);
            nums[i]=A[i];
        }
        sort(nums,nums+N);
        for(int i=0;i<N/B;++i)
            sort(bucket[i].begin(),bucket[i].end());

        for(int i=0;i<M;++i){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            l--;
            solve(l,r,k);
        }
        for (int i = 0; i <= N/B; i++) {
            bucket[i].clear();
        }
    }
    return 0;
}
