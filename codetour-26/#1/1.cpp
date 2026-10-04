#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<int, 100'005> a;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.begin() + n);

    for (int i = 0; i < n; ++i) {
        if (a[i] < i + 1) {
            cout << 0;
            return 0;
        }
    }

    return 0;
}
