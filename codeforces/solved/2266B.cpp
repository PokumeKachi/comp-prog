#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    while (t--) {
        long long a, b, c;

        cin >> a >> b >> c;

        if (a >= b || (a + c - b) > (b - a)) {
            res += to_string(a + c - b) + '\n';
        } else {
            res += to_string(b - a) + '\n';
        }
    }

    cout << res;

    return 0;
}
