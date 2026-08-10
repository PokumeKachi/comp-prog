#include <bits/stdc++.h>

const long long INF = 1e18;

#include <algorithm>
#include <cmath>

using namespace std;

struct Display {
    int fontSize;
    long long rentCost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Display displays[3'005];

    for (int i = 0; i < n; ++i) {
        cin >> displays[i].fontSize;
    }

    for (int i = 0; i < n; ++i) {
        cin >> displays[i].rentCost;
    }

    long long res = -1;

    for (int j = 1; j < n - 1; ++j) {
        long long left = INF;
        long long right = INF;

        for (int i = 0; i < j; ++i) {
            if (displays[i].fontSize < displays[j].fontSize) {
                left = min(left, displays[i].rentCost);
            }
        }

        for (int i = j + 1; i < n; ++i) {
            if (displays[i].fontSize > displays[j].fontSize) {
                right = min(right, displays[i].rentCost);
            }
        }

        if (left != INF && right != INF) {
            if (res == -1) res = INF;
            res = min(left + right + displays[j].rentCost, res);
        }
    }

    cout << res;

    return 0;
}
