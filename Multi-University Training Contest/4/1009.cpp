///多组可能数据...
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn];

int main()
{
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int num=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==1) num++;
        }
        if(num>=n-num) cout<<2<<" "<<1<<endl;
        else
            cout<<2<<" "<<0<<endl;
    }
    return 0;
}
