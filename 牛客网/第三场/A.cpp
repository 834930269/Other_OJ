#include<bits/stdc++.h>
using namespace std;
//M_PI,M_E
int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        if(n==0){
            printf("1\n");
            continue;
        }
        double ans=log(sqrt(2*M_PI*n))/log(8)+n*log(n/M_E)/log(8);
        printf("%d\n",(int)ans+1);
    }
    return 0;
}
