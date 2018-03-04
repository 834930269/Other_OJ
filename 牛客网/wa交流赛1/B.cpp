#include<iostream>
using namespace std;
int main()
{
    int t;
    long long a,b,c,d,v;
    int min;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d >> v;
        if(v%5==0)
            cout << a << endl;
        else
            cout << (b*5+c*10+d*50)/((v/5+1)*5)*((v/5+1)*5-v)+a << endl;
    }
    return 0;
}
