#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100010;

int seq[maxn],N;
int temp[maxn];
LL cnt;
//�鲢������������
void merge_sort(int arr[],int l,int r){
    if(l==r)return;
    int mid=((l+r)>>1);
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    int i=l,j=mid+1;
    for(int k=l;k<=r;++k){
        if(j>r || (i<=mid && arr[i]<arr[j]))temp[k]=arr[i++];
        else temp[k]=arr[j++],cnt+=mid-i+1;
        //���a[i]>a[j]������������mid+1-i,��ʣ�µ�ǰ�����
    }
    for(i=l;i<=r;++i)arr[i]=temp[i];
}

int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>seq[i];
    }
    cnt=0;
    merge_sort(seq,0,N-1);
    cout<<cnt<<endl;
    return 0;
}
