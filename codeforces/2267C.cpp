#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    string res;

    while (t--) {
        long long n, x;

        cin >> n >> x;

        array<long long, 300'005> a;

        long long maxCoins = 0;

        unordered_map<long long, int> profit;

        for (long long i = 0; i < n; ++i) {
            cin >> a[i];

            long long gcd = __gcd(a[i], x);

            if (gcd <= 1) {
                --n;
                --i;
            } else if (a[i] % x == 0) {
                maxCoins += a[i];
                --n;
                --i;
            } else {
                profit[gcd] += a[i];
            }
        }

        vector<pair<long long, int>> gcdProfits;

        for (const auto& [gcd, coins] : profit) {
            gcdProfits.emplace_back(gcd, coins);
        }

        if (gcdProfits.size()) {
            long long dpProfits = 0;

            sort(
                gcdProfits.begin(), gcdProfits.end(),
                [](const auto& a, const auto& b) { return a.first > b.first; });

            vector<long long> dp(gcdProfits.size());

            dp[0] = gcdProfits[0].second;
            dpProfits = gcdProfits[0].second;

            for (const auto& [gcd, profit] : gcdProfits) {
                // cout << gcd << ' ' << profit << '\n';
            }

            for (long long i = 1; i < gcdProfits.size(); ++i) {
                dp[i] = gcdProfits[i].second;
                for (long long j = i - 1; j >= 0; --j) {
                    if (__gcd(gcdProfits[j].first, gcdProfits[i].first) > 1) {
                        dp[i] = max(dp[i], dp[j] + gcdProfits[i].second);
                    }
                }

                dpProfits = max(dpProfits, dp[i]);
            }

            maxCoins += dpProfits;
        }

        res += to_string(maxCoins) + '\n';
    }

    cout << res;

    return 0;
}
