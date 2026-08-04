#include <bits/stdc++.h>

using namespace std;

int w[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string res = "";

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }

        if (n % 2 == 1) {
            res.append("NO\n");
            continue;
        }

        int high = 1000000005;
        int low = -1;

        for (int i = 0; i + 1 < n; i += 2) {
            low = max(low, w[i + 1]);
            high = min(high, w[i]);

            if (low >= high - 1) {
                res.append("NO\n");
                break;
            }
        }

        if (low < high - 1) {
            res.append("YES\n");
        }
    }

    cout << res;

    return 0;
}
