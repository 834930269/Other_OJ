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
	///��һ��if�ų��˴󲿷ֿ���
	///�������ڸ������Ǿ��Բ����ܵ�
	if(s>8*n) printf("NO");
	else if(s==8*n){
        ///�������+1�����˵Ļ�,���ǡ���������ڸ�����
        ///���������С������,һ���޷���������
        ///�������С�ڸ�����,һ������.
		if(k==n*4&&j<n) printf("NO");
		else printf("YES");
	}
	else printf("YES");
	return 0;
}
