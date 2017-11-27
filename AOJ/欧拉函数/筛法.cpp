#include<iostream>
#include<algorithm>
using namespace std;

///É¸·¨Çóeuler(1)~euler(n)
const int maxn=101;
int euler_1_n[maxn];

void a_euler(){
    euler_1_n[1]=1;
    for(int i=2;i<maxn;++i) euler_1_n[i]=i;
    for(int i=2;i<maxn;++i){
        if(euler_1_n[i]==i){
            for(int j=i;j<maxn;j+=i){
                euler_1_n[j]=euler_1_n[j]/i*(i-1);
            }
        }
    }
}

int main(){
    a_euler();
    for(int i=1;i<101;++i)
        cout<<euler_1_n[i]<<endl;

    return 0;
}
