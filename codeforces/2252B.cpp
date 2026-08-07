#include <bits/stdc++.h>

#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int deleteZeros = 0;
        int deleteOnes = 0;

        int blocks = 1;

        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') ++zeroCount;
            else ++oneCount;
        }

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                if (s[i] == '0') {
                    ++deleteZeros;
                } else {
                    ++deleteOnes;
                }
            } else {
                ++blocks;
            }
        }

        int extraOps = abs(deleteOnes - deleteZeros);
        int countDiff = abs(oneCount - zeroCount);

        if (extraOps <= 1) {
            res += to_string(deleteOnes + deleteZeros);
        } else {
            // if (extraOps)
            res += to_string(countDiff) + ' ' + to_string(blocks) + ' ' + to_string(extraOps);
        }

        res += '\n';
    }

    cout << res;

    return 0;
}
