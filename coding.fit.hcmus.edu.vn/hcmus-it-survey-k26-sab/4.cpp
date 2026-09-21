#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, S;

    cin >> n >> S;

    long long a[100'005];

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long res = 0;

    for (long long i = 0; i < n; ++i) {
        if (a[i] > (S / 2)) break;
        if (a[i] == S / 2 && S % 2 == 0) {
            long long block = upper_bound(a, a + n, a[i]) - a - i;

            if (block > 1) {
                // res += fact[block] / (fact[block - 2] * 2);
                res += block * (block - 1) / 2;
            }

            break;
        }

        long long low = lower_bound(a, a + n, S - a[i]) - a;
        long long high = upper_bound(a, a + n, S - a[i]) - a;

        res += high - low;
    }

    cout << res;

    return 0;
}
