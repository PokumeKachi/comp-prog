#include <bits/stdc++.h>

using namespace std;

int mountainMap[105] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;

    cin >> m >> n;

    string input;

    for (int i = 0; i < m; ++i) {
        cin >> input;

        for (int j = 0; j < n; ++j) {
            if (mountainMap[j] > 0) {
                continue;
            }

            if (input[j] == '*') {
                mountainMap[j] = m - i;
            }
        }
    }

    int greatestClimb = 0;
    int greatestDescent = 0;

    for (int j = 1; j < n; ++j) {
        if (mountainMap[j] > mountainMap[j - 1]) {
            greatestClimb = max(greatestClimb, mountainMap[j] - mountainMap[j - 1]);
        } else {
            greatestDescent = max(greatestDescent, mountainMap[j - 1] - mountainMap[j]);
        }
    }

    cout << greatestClimb << ' ' << greatestDescent;

    return 0;
}
