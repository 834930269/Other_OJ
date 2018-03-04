/*
链接：https://www.nowcoder.com/acm/contest/71/C
来源：牛客网

小W在计算一个数列{An},其中A1=1,A2=2,An+2=An+1+An。
尽管他计算非常精准，但很快他就弄混了自己的草稿纸，
他找出了一些他计算的结果，但他忘记了这些都是数列中的第几项。

链接：https://www.nowcoder.com/acm/contest/71/C
来源：牛客网

输入描述:

每行包括数列中的一项Ak(k<=100000)。

总行数T<=30。

输出描述:

对于每一项Ak，输出一行包括一个正整数k表示输入中数是数列的第几项。

示例1
输入

2
3
5
8
13

输出

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
