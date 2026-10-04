#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, S, D;

    cin >> n >> S >> D;

    array<int, 200'005> a;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.data(), a.data() + n);

    if ((a[n - 1] << 1) < S) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i :)

    return 0;
}
