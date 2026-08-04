#include <bits/stdc++.h>
#include <string>

#define B 31

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mask[B];
    for (int b = 0; b < B; b++) mask[b] = 1 << b;

    int n;
    int a[100'005];

    cin >> n;

    int record[B] = {0};

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        for (int b = 0; b < B; b++) {
            if (mask[b] & a[i]) {
                ++record[b];
            }
        }
    }

    int bestValue = -1;
    int bestValueIndex = -1;

    for (int i = 0; i < n; ++i) {
        int value = 0;

        for (int b = 0; b < B; b++) {
            if (record[b] == 1) {
                if (mask[b] & a[i]) {
                    value |= mask[b];
                }
            }
        }

        if (bestValue < value) {
            bestValue = value;
            bestValueIndex = i;
        }
    }

    swap(a[bestValueIndex], a[0]);

    string res;

    for (int i = 0; i < n; ++i) {
        res += to_string(a[i]) + ' ';
    }

    cout << res;

    return 0;
}
