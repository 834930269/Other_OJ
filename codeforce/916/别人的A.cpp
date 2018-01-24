#include<bits/stdc++.h>
using namespace std;
int x,hh,mm,ans;
int main()
{
	cin>>x>>hh>>mm;
 	while(mm%10!=7&&hh%10!=7)
	{
		mm-=x;
		if(mm<0) mm+=60,hh--;
		if(hh<0) hh+=24;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
