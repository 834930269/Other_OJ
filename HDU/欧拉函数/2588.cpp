#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int euler(int n){
    int res=n,a=n;
    for(int i=2;i*i<=a;++i){
        if(a%i==0){
            ///��(N)=N*(1-1/P1)*(1-1/P2)...����P��������
            res=res/i*(i-1);//�Ƚ��г�����Ϊ��Ԥ�����
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        int ans=0;
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=1;i*i<=N;++i){
            if(N%i==0){
                if(i>=M)
                    ans+=euler(N/i);
                if((N/i)!=i && (N/i)>=M)
                ///���==i��>=M�Ļ�֤��i>=M,������Ҫ��������,�����ų���
                    ans+=euler(i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
