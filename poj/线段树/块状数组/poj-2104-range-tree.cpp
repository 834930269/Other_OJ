#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
///�߶����¹鲢����
///�鲢��
const int ST_SIZE=(1<<18)-1;
const int MAX_N=100000+10;
const int MAX_M=5000+10;
///����
int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];

int nums[MAX_N];///��A����֮��Ľ��
vector<int> dat[ST_SIZE];///�߶���������

///�����߶���
///k�ǽڵ�ı��,������[l,r)��Ӧ
void build(int k,int l,int r){
    if(r-l==1){
        dat[k].push_back(A[l]);
    }else{
        int lch=(k<<1)+1,rch=(k<<1)+2;
        build(lch,l,(l+r)>>1);
        build(rch,(l+r)>>1,r);
        ///��ǰ����ռ�Ų������
        dat[k].resize(r-l);
        ///����STL��merge�������������ӵ����кϲ���һ����������
        merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),dat[k].begin());
    }
}

///����[a,b)�в�����x�����ĸ���
int query(int a,int b,int x,int k,int l,int r){
    if(l>=b || r<=a){
        ///��ȫ���ཻ
        return 0;
    }else if(a<=l&&r<=b){
        ///��ȫ����������
        return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
    }else{
        ///�ݹ������ӽڵ�
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
