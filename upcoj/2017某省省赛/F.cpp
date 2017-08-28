#include<bits/stdc++.h>
using namespace std;
int N,ca=1,T;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(N%2==1)
        {
            printf("Case #%d:\n%d",ca++,N);
            for(int i=N-1;i>=1;--i) printf(" %d",i);
            printf("\n");
        }else
        {
            printf("Case #%d:\n-1\n",ca++,N);
        }

    }
    return 0;
}

/**************************************************************
    Problem: 1052
    User: team86
    Language: C++
    Result: ÕýÈ·
    Time:16 ms
    Memory:1540 kb
****************************************************************/
