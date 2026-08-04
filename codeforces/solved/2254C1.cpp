#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    string res;

    while (t--) {
        long long n;

        string a, b;

        cin >> n >> a >> b;

        long long evenIndicesOfA = 0;
        long long oddIndicesOfA = 0;

        long long evenIndicesOfB = 0;
        long long oddIndicesOfB = 0;

        for (long long i = 0; i < n; ++i) {
            if (a[i] == '1') {
                if (i % 2) ++evenIndicesOfA;
                else ++oddIndicesOfA;
            }

            if (b[i] == '1') {
                if (i % 2) ++evenIndicesOfB;
                else ++oddIndicesOfB;
            }
        }

        if (evenIndicesOfA == evenIndicesOfB && oddIndicesOfA == oddIndicesOfB) {
            res += "YES\n";
        } else {
            res += "NO\n";
        }
    }

    cout << res;

    return 0;
}
