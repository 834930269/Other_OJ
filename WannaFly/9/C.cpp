/*
���ӣ�https://www.nowcoder.com/acm/contest/71/C
��Դ��ţ����

СW�ڼ���һ������{An},����A1=1,A2=2,An+2=An+1+An��
����������ǳ���׼�����ܿ�����Ū�����Լ��Ĳݸ�ֽ��
���ҳ���һЩ������Ľ����������������Щ���������еĵڼ��

���ӣ�https://www.nowcoder.com/acm/contest/71/C
��Դ��ţ����

��������:

ÿ�а��������е�һ��Ak(k<=100000)��

������T<=30��

�������:

����ÿһ��Ak�����һ�а���һ��������k��ʾ�������������еĵڼ��

ʾ��1
����

2
3
5
8
13

���

2
3
4
5
6
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;

const LL MAXN = 10000000000;

int main()
{
    int n;
    char a[10005];
    LL fi[100005];
    fi[1] = 1;
    fi[2] = 2;
    for(int i = 3; i <= 100000; i++)
    {
        fi[i] = (fi[i - 1] + fi[i - 2]) % MAXN;
    }
    //scanf("%d", &n);
    memset(a, 0, sizeof(a));
    while(~scanf("%s", a + 1))
    {
        int len = strlen(a + 1);
        LL p = 0;
        for(int i = max(len - 9, 1); i <= len; i++)
        {
            p = p * 10 + (LL)(a[i] - '0');
        //  printf("%d***\n", p);
        }
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 100000; i++)
        {
            if(fi[i] == p) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
