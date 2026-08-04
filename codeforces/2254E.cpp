#include <algorithm>
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
        array<int, 200'005> b;

        cin >> n;

        array<int, 200'006> prefixSum;

        prefixSum[0] = 0;

        for (int i = 0; i < n; ++i) {
            cin >> b[i];

            prefixSum[i + 1] = prefixSum[i] + b[i];
        }

        int indexOf0 = -1;

        for (int i = 0; i < n; ++i) {
            if (b[i] <= 0) continue;
            if (b[i] + prefixSum[n] - prefixSum[i + 1] + prefixSum[i] <= 0)
                continue;
            ;

            if (indexOf0 == -1) {
                indexOf0 = i;
            } else {
                if (b[indexOf0] > b[i]) {
                    indexOf0 = i;
                }
            }
        }

        if (indexOf0 == -1) {
            res += "-1\n";
            continue;
        }

        int baseElement = b[indexOf0];

        array<int, 200'005> ups;
        int upCount = 0;

        array<int, 200'005> downs;
        int downCount = 0;

        for (int i = 0; i < n; ++i) {
            if (i == indexOf0) continue;

            if (b[i] < 0) {
                downs[downCount++] = b[i];
            } else {
                ups[upCount++] = b[i];
            }
        }

        sort(ups.begin(), ups.begin() + upCount);
        sort(downs.begin(), downs.begin() + downCount);

        int i = 0;
        int j = 0;

        int currentElement = baseElement;

        res += to_string(currentElement) + ' ';

        while (i < upCount || j < downCount) {
            if (i == upCount) {
                currentElement += downs[j++];
            } else {
            }

            res += to_string(currentElement) + ' ';
        }
    }

    cout << res;

    return 0;
}
