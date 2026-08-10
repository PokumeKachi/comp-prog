#include <bits/stdc++.h>

#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    // bool primes[200'005];
    // fill(primes, primes + 200005, true);

    while (t--) {
        int n;
        cin >> n;

        int a[200'005];
        fill(a, a + 200005, -1);
        int adjacents = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];

            if (a[i] == a[i - 1]) {
                ++adjacents;
            }
        }

        int maxSave = 0;

        for (int i = 1; i <= n; ++i) {
            if (a[i] == a[i - 1]) {
                int toSwap = i - 1;

                if (a[toSwap] != a[toSwap - 1] && a[toSwap] != a[toSwap - 2] && a[toSwap - 1] != -1) {
                    if (a[toSwap - 1] != -1 && a[toSwap - 1] == a[toSwap - 2]) {
                        maxSave = max(maxSave, 2);
                        break;
                    } else {
                        maxSave = max(maxSave, 1);
                    }
                }

                toSwap = i;

                if (a[toSwap] != a[toSwap + 1] && a[toSwap] != a[toSwap + 2] && a[toSwap + 1] != -1) {
                    if (a[toSwap + 1] != -1 && a[toSwap + 1] == a[toSwap + 2]) {
                        maxSave = max(maxSave, 2);
                        break;
                    } else {
                        maxSave = max(maxSave, 1);
                    }
                }
            }
        }

        res += to_string(n - adjacents + maxSave);

        res += '\n';
    }

    cout << res;

    return 0;
}
