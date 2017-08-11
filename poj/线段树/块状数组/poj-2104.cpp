///������poj����������.���ֱ�����- -TLE
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int B=1000;///Ͱ�Ĵ�С
const int MAX_N=100000+10;
const int MAX_M=5000+10;
///����
int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];

int nums[MAX_N]; ///��A�����Ľ��
vector<int> bucket[MAX_N / B]; ///ÿ��Ͱ����֮��Ľ��

void solve(int l,int r,int k){
    ///��[l,r)�����е�k����
    int lb=-1,ub=N-1;
    while(ub-lb>1){
        int md=(lb+ub)>>1;
        int x=nums[md];
        int tl=l,tr=r,c=0;

        ///�������˶���Ĳ���
        while(tl<tr && tl % B !=0) if(A[tl++]<=x) c++;
        while(tl<tr && tr % B !=0) if(A[--tr]<=x) c++;

        ///��ÿһ��Ͱ���м���
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
