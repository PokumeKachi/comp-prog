#include <bits/stdc++.h>

#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[105];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    int b[105];

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int res = 0;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            ++res;
            ++i;
            ++j;
        } else {
            if (a[i] < b[j])
                ++i;
            else
                ++j;
        }
    }

    cout << res;

    return 0;
}
