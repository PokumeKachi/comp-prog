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
        cin >> n;

        array<int, 105> a;
        fill(a.begin(), a.begin() + 105, 0);

        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            ++a[input];
        }

        int soFar = 0;

        while (soFar < n) {
            for (int i = 101; i >= 0; --i) {
                if (a[i]) {
                    res += to_string(i) + ' ';
                    ++soFar;
                    --a[i];
                }
            }
        }

        res += '\n';
    }

    cout << res;

    return 0;
}
