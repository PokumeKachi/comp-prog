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
        int length;
        string s;
        cin >> length >> s;

        long long ops = 0;

        bool theresOneBefore = false;
        bool theresZeroBefore = false;

        long long dp[2][200'005];
        dp[0][0] = dp[1][length - 1] = 0;

        if (s[0] == '0') {
            int firstOneIndex = -1;

            for (int i = 1; i < length; ++i) {
                if (s[i] == '0') {
                    dp[0][i] = dp[0][i - 1];
                } else {
                    dp[0][i] = dp[0][i - 1] + 1;

                    if (firstOneIndex == -1) {
                        firstOneIndex = i;
                    }
                }
            }

            if (s[length - 1] == '0') dp[1][length - 1] = 1;
            else dp[1][length - 1] = 0;

            for (int i = length - 2; i >= 0; --i) {
                if (s[i] == '0') {
                    dp[1][i] = dp[1][i + 1] + 1;
                } else {
                    dp[1][i] = dp[1][i + 1];
                }
            }

            ops = 1'000'000'000;

            for (int i = 1; i < length; ++i) {
                ops = min(ops, dp[0][i - 1] + dp[1][i]);
            }

            ops = min(ops, min(dp[0][length - 1], dp[1][0]));


            // res += '\n';
            // res += '\n';
            // for (int i = 0; i < length; ++i) {
            //     res += to_string(dp[0][i]) + ' ';
            // }
            // res += '\n';
            // for (int i = 0; i < length; ++i) {
            //     res += to_string(dp[1][i]) + ' ';
            // }
            // res += '\n';
            // res += '\n';

        } else {
            for (int i = 1; i < length; ++i) {
                if (s[i] == '0') ++ops;
            }
        }

        res += to_string(ops) + '\n';
    }

    cout << res;

    return 0;
}
