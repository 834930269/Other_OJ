#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int A[maxn],ans,ran[8],N;

void init(){
    for(int i=0;i<maxn;i+=100){
        ran[1]=1500*0.97;
        ran[2]=3000*0.90;
        ran[3]=4500*0.80;
        ran[4]=(35000-9000)*0.75;
        ran[5]=20000*0.70;
        ran[6]=25000*0.65;
        int S=i-3500;
        if(i<=3500) A[i]=i;
        else if(S<=1500) ans=S*0.97+3500,A[ans]=i;
        else if(S<=4500) ans=3500+ran[1]+(S-1500)*0.90,A[ans]=i;
        else if(S<=9000) ans=3500+ran[1]+ran[2]+(S-4500)*0.80,A[ans]=i;
        else if(S<=35000) ans=3500+ran[1]+ran[2]+ran[3]+(S-9000)*0.75,A[ans]=i;
        else if(S<=55000) ans=3500+ran[1]+ran[2]+ran[3]+ran[4]+(S-35000)*0.70,A[ans]=i;
        else if(S<=80000) ans=3500+ran[1]+ran[2]+ran[3]+ran[4]+ran[5]+(S-55000)*0.65,A[ans]=i;
        else ans=3500+ran[1]+ran[2]+ran[3]+ran[4]+ran[5]+ran[6]+(S-80000)*0.55,A[ans]=i;
    }
}

int main(){
    init();
    while(~scanf("%d",&N)){
        printf("%d\n",A[N]);
    }
    return 0;
}
