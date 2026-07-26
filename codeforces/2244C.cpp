#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

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

        if (is_sorted(p.begin(), p.begin() + n) || ((x & 1) ^ (y & 1)) || (x == 1 || y == 1)) {
            output.append("YES\n");
        } else {
            output.append("NO\n");
        }
    }

    cout << output;

    return 0;
}
