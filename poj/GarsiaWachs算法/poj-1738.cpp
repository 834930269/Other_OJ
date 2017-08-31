///186 64 35 32 103
///GarsiaWachs�㷨��ʱ�临�Ӷ�ΪO(n^2),ƽ�������Ż���ʹ�����ո��Ӷ�ΪO(nlogn)
/*
��������stone[]���������ң���һ������
stone[k-1] <= stone[k+1]��k���ҵ����
��stone[k]��stone[k-1]���ٴӵ�ǰλ��
��ʼ����������j��ʹ������
stone[j] > stone[k]+stone[k-1]��
�嵽j�ĺ�����С�һֱ�ظ���ֱ��ֻʣ��
һ��ʯ�ӾͿ����ˡ�����������У����Լ���
stone[-1]��stone[n]��������ġ�
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
