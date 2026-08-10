#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    long long a[200'005];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long prefixDiff[200'005] = {0};

    int queryStart;
    int queryEnd;

    for (int i = 0; i < q; ++i) {
        cin >> queryStart >> queryEnd;
        ++prefixDiff[queryStart - 1];
        --prefixDiff[queryEnd];
    }

    for (int i = 1; i < n; ++i) {
        prefixDiff[i] += prefixDiff[i - 1];
    }

    sort(a, a + n, greater<long long>());
    sort(prefixDiff, prefixDiff + n, greater<long long>());

    long long res = 0;

    for (int i = 0; i < n; ++i) {
        if (!prefixDiff[i]) break;
        res += prefixDiff[i] * a[i];
    }

    cout << res;

    return 0;
}
