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
        int a[3];

        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);

        int rounds = min(a[2] - a[1], a[1] - a[0]);

        res += to_string(rounds) + '\n';
    }

    cout << res;

    return 0;
}
