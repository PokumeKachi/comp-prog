#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        long long count = 0;

        for (int i = 0; i < (n >> 1); ++i) {
            if (s[i] == s[n - 1 - i]) {
                continue;
            } else if (s[i] == c || s[n - 1 - i] == c) {
                 ++count;
            } else {
                count += 2;
            }
        }

        res += to_string(count) + '\n';

    }

    cout << res;

    return 0;
}
