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

        string a, b;

        cin >> n >> a >> b;

        vector<int> evenIndices[2];
        vector<int> oddIndices[2];

        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                ((i % 2 == 0) ? evenIndices : oddIndices)[0].push_back(i);
            }

            if (b[i] == '1') {
                ((i % 2 == 0) ? evenIndices : oddIndices)[1].push_back(i);
            }
        }

        if (evenIndices[0].size() != evenIndices[1].size() || oddIndices[0].size() != oddIndices[1].size()) {
            res += "-1\n";
            continue;
        }

        long long operations = 0;

        for (int i = 0; i < evenIndices[0].size(); ++i) {
            operations += abs(evenIndices[0][i] - evenIndices[1][i]) >> 1;
        }

        for (int i = 0; i < oddIndices[0].size(); ++i) {
            operations += abs(oddIndices[0][i] - oddIndices[1][i]) >> 1;
        }

        res += to_string(operations) + '\n';
    }

    cout << res;

    return 0;
}
