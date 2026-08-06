#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int a[100'005];

    set<int> record;
    int dp[100'005];
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        record.insert(a[i]);
        dp[i + 1] = record.size();
    }

    string res;

    int l;

    for (int i = 0; i < m; ++i) {
        cin >> l;

        res += to_string(dp[l]) + '\n';
    }

    cout << res;

    return 0;
}
