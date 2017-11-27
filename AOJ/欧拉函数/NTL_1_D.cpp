#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

///返回euler(n)
int euler(int n){
    int res=n,a=n;
    for(int i=2;i*i<=a;++i){
        if(a%i==0){
            ///φ(N)=N*(1-1/P1)*(1-1/P2)...其中P是素因子
            res=res/i*(i-1);//先进行除法方为了预防溢出
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<euler(n)<<endl;

    return 0;
}
