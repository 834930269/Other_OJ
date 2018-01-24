//https://www.nowcoder.com/acm/contest/57/D
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, m, L, R;
    while (~scanf("%d%d%d%d%d%d", &n, &l, &r, &m, &L, &R)) {

        int A = 0, B = 0;
        for (int i = l; i <= r; ++i)
            for (int j = L; j <= R; ++j) {
                if (i > j) ++A;
                if (i < j) ++B;
            }
        double p = A * 1.0 / (A + B);
        double ans;
        if (p > 0) {
            if (n > 0) ans = n * p / (n * p + m * (1-p));
            else ans = 0;
        } else {
            if (m > 0) ans = 0;
            else ans = 1;
        }
        printf("%.5f\n", ans);
    }
    return 0;
}
