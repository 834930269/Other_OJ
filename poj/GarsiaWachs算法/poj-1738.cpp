///186 64 35 32 103
///GarsiaWachs算法。时间复杂度为O(n^2),平衡树来优化，使得最终复杂度为O(nlogn)
/*
设序列是stone[]，从左往右，找一个满足
stone[k-1] <= stone[k+1]的k，找到后合
并stone[k]和stone[k-1]，再从当前位置
开始向左找最大的j，使其满足
stone[j] > stone[k]+stone[k-1]，
插到j的后面就行。一直重复，直到只剩下
一堆石子就可以了。在这个过程中，可以假设
stone[-1]和stone[n]是正无穷的。
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50005;

int stone[maxn];
int N,ans,T;
///186 64 35 32 103
void combine(int k){
    int tmp=stone[k]+stone[k-1];
    ans+=tmp;
    for(int i=k;i<T-1;++i)
        stone[i]=stone[i+1];
    T--;
    int j=0;
    for(j=k-1;j>0&&stone[j-1]<tmp;--j)
        stone[j]=stone[j-1];
    stone[j]=tmp;
    while(j>=2&&stone[j]>=stone[j-2]){
        int d=T-j;
        combine(j-1);
        j=T-d;
    }
}

int main(){
    while(~scanf("%d",&N)&&N){
        for(int i=0;i<N;++i) scanf("%d",&stone[i]);
        T=1;
        ans=0;
        for(int i=1;i<N;++i){
            stone[T++]=stone[i];
            while(T>=3&&stone[T-3]<=stone[T-1]){
                combine(T-2);
            }
        }
        while(T>1)combine(T-1);
        printf("%d\n",ans);
    }
    return 0;
}
///186 64 35 32 103
