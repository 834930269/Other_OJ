#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    int n;n = read();
    int res = 1000000000;
    for(int i = 1;i <= n;i++) {
        a[i] = read();
        if(i > 1) {
            res = min(res,1 + a[i] * a[i]);
        }
        if(i > 2) {
            res = min(res,4 + (a[i] + a[i-1]) * (a[i] + a[i-1]));
        }
    }
    cout<<res<<endl;
    return 0;
}
