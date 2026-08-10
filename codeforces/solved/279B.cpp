#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    int a[100'005];
    int prefixSum[100'005] = {0};

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        int end = upper_bound(prefixSum, prefixSum + n + 1, prefixSum[i - 1] + t) - prefixSum - 1;
        res = max(res, end - i + 1);
    }

    cout << res;

    return 0;
}
