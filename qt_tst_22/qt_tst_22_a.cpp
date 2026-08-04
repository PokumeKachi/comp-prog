#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a[2'000'005];
    int p, q, r;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> p >> q >> r;

    long long countOfR = 0;
    long long countOfQR = 0;
    long long ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == p) {
            ans += countOfQR;
        }

        if (a[i] == q) {
            countOfQR += countOfR;
        }

        if (a[i] == r) {
            ++countOfR;
        }
    }

    cout << ans;

    return 0;
}
