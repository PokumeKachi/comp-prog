#include <bits/stdc++.h>

#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n;
        cin >> n;

        int a[55];

        int count[1005] = {0};

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++count[a[i]];
        }

        long long dmg = 0;

        for (int i = 0; i < 1005; ++i) {
            if (count[i] > (n / 2) + 1) {
                int theRest = n - count[i];
                dmg += theRest * i + 2 * i;
            } else {
                dmg += i * count[i];
            }
        }

        res += to_string(dmg) + '\n';
    }

    cout << res;

    return 0;
}
