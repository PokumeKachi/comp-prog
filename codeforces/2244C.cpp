#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    // if (t == 10000) {
    //     for (int i = 1; i <= t; ++i) {
    //         int n, x, y;
    //
    //         cin >> n >> x >> y;
    //
    //         std::array<int, 200005> p;
    //
    //         for (int j = 0; j < n; ++j) {
    //             int input;
    //             cin >> input;
    //             p[j] = input;
    //         }
    //
    //         if (i == 92) {
    //             cout << n << ' ' << x << ' ' << y << '\n';
    //
    //             for (int j = 0; j < n; ++j) {
    //                 cout << p[j] << ' ';
    //             }
    //         }
    //     }
    // }

    string output = "";

    for (int i = 0; i < t; ++i) {
        int n, x, y;

        cin >> n >> x >> y;

        std::array<int, 200005> p;

        for (int j = 0; j < n; ++j) {
            int input;
            cin >> input;
            p[j] = input;
        }

        if (is_sorted(p.begin(), p.begin() + n) || ((x & 1) ^ (y & 1)) ||
            (x == 1 || y == 1)) {
            output.append("YES\n");
        } else {
            int shiftDistance = gcd(x, y);

            if (shiftDistance == 1) {
                output += "YES\n";
                continue;
            }

            std::array<int, 200005> sorted = p;

            sort(sorted.begin(), sorted.begin() + n);

            bool fucked = false;

            for (int j = 0; j < n; ++j) {
                int element = p[j];
                int low =
                    lower_bound(sorted.begin(), sorted.begin() + n, element) -
                    sorted.begin();
                int high =
                    upper_bound(sorted.begin(), sorted.begin() + n, element) -
                    sorted.begin() - 1;

                if ((low <= j && j <= high)) continue;

                int shift1 = abs(low - j);
                int shift2 = abs(high - j);

                if (min(shift1, shift2) % shiftDistance == 0) continue;
                if (min(shift1, shift2) + (shiftDistance - min(shift1, shift2) % shiftDistance) <= max(shift1, shift2)) continue;

                output.append("NO\n");
                fucked = true;
                break;
            }

            if (!fucked) {
                output.append("YES\n");
            }
        }
    }

    cout << output;

    return 0;
}
