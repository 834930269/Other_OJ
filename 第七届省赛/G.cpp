#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans,pp;
    int i;
    long long int f[100];
    f[2]=1;
    f[1]=0;
    f[0]=0;
    for(i=3;i<30;i++)
        f[i]=f[i-1]*3+1;
    long long int a;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a;
        ans=0;
        if(a%2)
        {
            cout<<0<<endl;
            continue;
        }
        while(a!=0)
        {
            pp=a%2;
            if(pp)
                ans++;
            a/=2;
        }
        cout<<f[ans]<<endl;
    }
}
