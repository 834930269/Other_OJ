#include<bits/stdc++.h>
using namespace std;

const int maxn=2000;

struct Star{
    int num,digit;
    bool operator<(const Star& b)const{
        if(num==b.num){
            return digit<b.digit;
        }
        return num>b.num;
    }
}dt[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        dt[num].num++;
        dt[num].digit=num;
    }
    sort(dt,dt+maxn);
    for(int i=0;dt[i].num!=0;++i){
        printf("%d %d\n",dt[i].digit,dt[i].num);
    }
    return 0;
}
