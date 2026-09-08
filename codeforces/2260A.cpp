#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[55];

        bool firstIsEasy = false;
        bool lastIsEasy = false;

        int easyCount = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            if (a[i] == 0) {
                ++easyCount;
            }
        }

        firstIsEasy = a[0] == 0;
        lastIsEasy = a[n - 1] == 0;

        if (easyCount < 2) {
            cout << -1 << '\n';
        } else {
            if (firstIsEasy && lastIsEasy)
                cout << 0 << '\n';
            else if (firstIsEasy | lastIsEasy)
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }

    return 0;
}
