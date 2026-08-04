#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    long long a[2'00'005];

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long res = 0;

    if (k > (n >> 1)) {
        // greedy

        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) {
                res += a[i] - a[i - 1];
            }
        }
    } else {
        // dynamic programming

        const int MAXN = 200005;

        long long dp1[MAXN];
        long long dp2[MAXN];

        long long* prev = dp1;
        long long* cur = dp2;

        for (int i = 1; i <= k; ++i) {
            long long best = prev[0] - a[0];

            for (int j = 1; j < n; ++j) {
                cur[j] = max(cur[j - 1], best + a[j]);
                best = max(best, prev[j] - a[j]);
            }

            swap(prev, cur);
        }

        res = prev[n - 1];
    }

    cout << res;

    return 0;
}
