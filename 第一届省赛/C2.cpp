#include <stdio.h>
#include<algorithm>
#include <string.h>
using namespace std;
struct Point //  ����һ�� Ԫ�� (���) �Ľṹ�塣
{
    int x;
    int y;
}point[1005],p[1005];
bool cmp(Point a,Point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int n,count_case = 1,i,j,k;
    while(scanf("%d",&n)&&n)
    {
        for(i = 0;i<n;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
            p[i].x = point[i].x;p[i].y = point[i].y;// ����һ������
        }
        std::sort(p,p+n,cmp);  //  ���������ݱ���
        printf("Case %d:\n",count_case++);
        for(i = 0;i<n;i++)
        {
            j = 0;
            while((point[i].x>=p[j].x||point[i].y>=p[j].y)&&j<n)//  ������������Ԫ�� �� x y ��Ҫ��ʾ��С ���������������ѭ��
                j++;
            if(j<n)
                printf("%d %d\n",p[j].x,p[j].y);//  �ҵ��˱� ���Ԫ�� �� x y ���Ԫ�أ����
            else
                printf("-1 -1\n");//  û�ҵ������ -1 -1
        }
        printf("\n");
    }
    return 0;
}
