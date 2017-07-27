#include<bits/stdc++.h>
using namespace std;
int main(){
    int kase=0;
    double t=log(2)/log(10),n;
    while(~scanf("%lf",&n)){
        int a=n*t;
        printf("Case #%d: %d\n",++kase,a);
    }
    return 0;
}
