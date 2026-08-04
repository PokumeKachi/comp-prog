#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    string res = "";

    while (t--) {
        int s, k, m;

        cin >> s >> k >> m;

        int elapsed = m % k;

        if (s <= k) {
            res += to_string(max(0, s - elapsed)) + "\n";
        } else {
            int flips = m / k;

            if (flips & 1) {
                res += to_string(max(0, k - elapsed)) + "\n";
            } else {
                res += to_string(max(0, s - elapsed)) + "\n";
            }
        }
    }

    cout << res;

    return 0;
}
