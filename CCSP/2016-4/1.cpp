#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b[10000],cnt=0;
    scanf("%d",&a);
    for(int i=0;i<a;++i) scanf("%d",&b[i]);
    for(int i=1;i<a-1;++i) if((b[i-1]>b[i]&&b[i+1]>b[i])||(b[i-1]<b[i]&&b[i+1]<b[i]))cnt++;
    cout<<cnt<<endl;
    return 0;
}
