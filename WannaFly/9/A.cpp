/*
���ӣ�https://www.nowcoder.com/acm/contest/71/A
��Դ��ţ����

��Ŀ����
����n�������������ҳ������ж��ٸ���x���㣺����n�����д�����y=kx������kΪ����1������
��������:

��һ������һ��n
������һ������n��������ai

�������:

���������������

ʾ��1
����

5
1 2 3 4 5

���

2

˵��

5������1��2����������1�Ǻ���ÿ���������ӣ�2��4������

��ע:

1��n,ai��1000000
*/
//ֱ�ӱ������Ӷ�Onlgn,�ܺ���
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
