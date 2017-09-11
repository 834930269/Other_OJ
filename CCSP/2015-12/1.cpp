#include<bits/stdc++.h>
using namespace std;

int readchar(){
    int ans=0;
    char st=getchar();
    while(isdigit(st)){
        ans+=(st-'0');
        st=getchar();
    }
    return ans;
}

int main(){
    printf("%d\n",readchar());
    return 0;
}
