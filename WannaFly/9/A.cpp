/*
链接：https://www.nowcoder.com/acm/contest/71/A
来源：牛客网

题目描述
给定n个正整数，请找出其中有多少个数x满足：在这n个数中存在数y=kx，其中k为大于1的整数
输入描述:

第一行输入一个n
接下来一行输入n个正整数ai

输出描述:

输出符合条件个数

示例1
输入

5
1 2 3 4 5

输出

2

说明

5个数中1和2符合条件，1是后面每个数的因子，2是4的因子

备注:

1≤n,ai≤1000000
*/
//直接暴力复杂度Onlgn,很合理
#include <bits/stdc++.h>
using namespace std;
#define IO std::ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
const int maxn = 1e6 + 10;
int cnt[maxn], n, x;
int main(void) {
    IO;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        mx = max(mx, x);
        cnt[x]++;
    }
    int ans= 0;
    for(int i = 1; i <= mx; ++i) {
        if(cnt[i]) {
            for(int j = i << 1; j <= mx; j += i) {
                if(cnt[j]) {
                    ans += cnt[i];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
