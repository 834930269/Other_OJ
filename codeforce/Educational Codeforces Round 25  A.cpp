#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        char digit,pre='0';
        int cnt=0;
        for(int i=0;i<n;++i){
            cin>>digit;
            if(digit=='1') cnt++;
            if(digit=='0') {printf("%d",cnt);cnt=0;}
        }
        if(digit=='1') printf("%d",cnt);
        if(digit=='0') printf("0");
        printf("\n");
    }
    return 0;
}
