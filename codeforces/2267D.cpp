#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    string res;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1 || n == 2) {
            res += "YES\n";
            continue;
        }

        array<pair<int, int>, 200'005> a;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;

            a[i].second = i & 1;
        }

        sort(a.begin(), a.begin() + n,
             [](const auto& a, const auto& b) { return a.first > b.first; });

        if (a[0].second == a[1].second) {
            res += "NO\n";
            continue;
        }

        if (a[0].second == a[2].second) {
            // top must be at the end
            if (a[0].second && (n & 1)) {
                res += "NO\n";
                continue;
            }

            bool getOut = false;

            for (int i = 3; i < n; ++i) {
                if (a[i].second == a[i - 1].second) {
                    getOut = true;
                    break;
                }
            }

            if (getOut) {
                res += "NO\n";
            } else {
                res += "YES\n";
            }
        } else {

        }
    }

    cout << res;

    return 0;
}
