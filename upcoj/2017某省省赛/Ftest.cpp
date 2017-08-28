#include<bits/stdc++.h>
using namespace std;
int num[100],N;
int main(){
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;++i) num[i-1]=i;
        int cnt=0;
        do{
            bool flag=true;
            for(int j=0;j<N;++j){
                for(int t=1;t<=N-num[j];++t){
                    int ind=(j+t)%N;
                    if(num[ind]==num[j]+t) flag=false;
                }
            }
            cnt++;
            if(flag){
                printf("%d th: ",cnt);
                for(int j=0;j<N;++j)
                    printf("%d ",num[j]);
                printf("\n");
            }
        }while(next_permutation(num,num+N));
    }
    return 0;
}
