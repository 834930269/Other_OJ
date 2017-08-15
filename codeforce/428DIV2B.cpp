#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,k,a[200],s,j;
	scanf("%d%d",&n,&k);
	for(i=0,s=0,j=0;i<k;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==1)
		{
			a[i]++;
			j++;
		}
		s+=a[i];
	}
	///第一个if排除了大部分可能
	///种数大于格子数是绝对不可能的
	if(s>8*n) printf("NO");
	else if(s==8*n){
        ///如果奇数+1坐满了的话,如果恰好种数等于格子数
        ///则如果奇数小于行数,一定无法满足题设
        ///如果种数小于格子数,一定成立.
		if(k==n*4&&j<n) printf("NO");
		else printf("YES");
	}
	else printf("YES");
	return 0;
}
