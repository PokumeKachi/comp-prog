#include <bits/stdc++.h>

using namespace std;

int a[1005];
int record[101] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int pastSum = 0;
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        totalSum += a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= a[i]; ++j) {
            int first = 100 * j / a[i];
            int second = 100 * (pastSum + j) / totalSum;

            if (first == second) {
                ++record[first];
            }
        }

        pastSum += a[i];
    }

    for (int i = 0; i <= 100; ++i) {
        if (record[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
