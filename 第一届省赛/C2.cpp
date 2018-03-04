#include <stdio.h>
#include<algorithm>
#include <string.h>
using namespace std;
struct Point //  定义一个 元素 (标记) 的结构体。
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
            p[i].x = point[i].x;p[i].y = point[i].y;// 拷贝一份数据
        }
        std::sort(p,p+n,cmp);  //  将拷贝数据备份
        printf("Case %d:\n",count_case++);
        for(i = 0;i<n;i++)
        {
            j = 0;
            while((point[i].x>=p[j].x||point[i].y>=p[j].y)&&j<n)//  遍历，如果标记元素 的 x y 比要显示的小 则继续，否则跳出循环
                j++;
            if(j<n)
                printf("%d %d\n",p[j].x,p[j].y);//  找到了比 标记元素 的 x y 大的元素，输出
            else
                printf("-1 -1\n");//  没找到，输出 -1 -1
        }
        printf("\n");
    }
    return 0;
}
