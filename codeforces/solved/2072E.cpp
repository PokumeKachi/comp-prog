#include <bits/stdc++.h>

using namespace std;

int combinatorics_dp[505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    combinatorics_dp[0] = 0;
    combinatorics_dp[1] = 0;

    for (int i = 2; i < 501; ++i) {
        combinatorics_dp[i] = (i * (i - 1)) >> 1;
    }

    int t;

    cin >> t;

    string res;

    while (t--) {
        int k;

        cin >> k;

        int placedStaff = 0;
        int remainingPairs = k;

        int x = 0, y = 0;
        bool incX = false;

        string staffCoords;

        staffCoords += to_string(x) + ' ' + to_string(y) + '\n';
        ++placedStaff;

        while (remainingPairs > 0) {
            int requiredPairedStaffs =
                upper_bound(combinatorics_dp, combinatorics_dp + 500,
                            remainingPairs) -
                combinatorics_dp - 1;


            for (int i = 1; i < requiredPairedStaffs; ++i) {
                if (incX) {
                    ++x;
                } else {
                    ++y;
                }

                staffCoords += to_string(x) + ' ' + to_string(y) + '\n';
                ++placedStaff;
            }

            incX = !incX;

            remainingPairs -= combinatorics_dp[requiredPairedStaffs];
        }

        res += to_string(placedStaff) + '\n' + staffCoords;
    }

    cout << res;

    return 0;
}
