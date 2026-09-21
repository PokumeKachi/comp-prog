#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int p[100'005];

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    long long res = n + 1;

    for (int i = 0; i < n; ++i) {
        int smallest = p[i];
        int biggest = p[i];

        for (int j = i + 1; j < n; ++j) {
            if (p[j] < smallest - 1 || p[j] > biggest + 1) break;
            smallest = min(smallest, p[j]);
            biggest = max(biggest, p[j]);
            ++res;
        }
    }

    cout << res;

    return 0;
}
