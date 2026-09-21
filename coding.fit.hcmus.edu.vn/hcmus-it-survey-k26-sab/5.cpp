#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;

    cin >> n >> k;

    long long w[100'005];

    long long prefix[100'005];
    prefix[0] = 0;

    for (long long i = 0; i < n; ++i) {
        cin >> w[i];
        prefix[i + 1] = prefix[i] + w[i];
    }

    array<long long, 100'005> dp;
    array<long long, 100'005> last;

    for (long long i = 0; i < n; ++i) {
        last[i] = prefix[i + 1];
    }

    for (long long i = 1; i < k; ++i) {
        for (long long j = i; j <= n; ++j) {
            dp[j] = 1e18;

            for (long long m = j; m >= i; --m) {
                dp[j] = min(dp[j], max(last[m - 1], prefix[j] - prefix[m]));
            }
        }

        last = dp;
    }

    long long res = 1e18;

    for (int i = k - 1; i <= n; ++i) {
        res = min(res, last[i]);
    }

    cout << res;

    return 0;
}
