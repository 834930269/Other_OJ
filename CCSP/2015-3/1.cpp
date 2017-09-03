#include<iostream>
using namespace std;
int i,j,n,m,temp=0,a[1000][1000];
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>a[i][j];
    for(i=m-1;i>=0;i--)
        for(j=0;j<n;j++)
        {
            cout<<a[j][i];
            ++temp;
            if(temp==n)
            {
                cout<<endl;
                temp=0;
            }
            else
                cout<<" ";
        }

    return 0;
}
