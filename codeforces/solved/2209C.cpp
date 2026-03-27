#include <bits/stdc++.h>

#define RES_CHECK \
    if (res) return;

using namespace std;

short t;
short reply;
int n;
int i, j;
int res;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cin >> reply;

    if (reply == 1) {
        return a;
    } else
        return 0;
}

void solve() {
    cin >> n;

    for (i = 2; i <= 2 * n - 4; i += 2) {
        res = query(i - 1, i);

        RES_CHECK
    }

    res = query(2 * n, 2 * n - 1);

    RES_CHECK

    res = query(2 * n, 2 * n - 2);

    RES_CHECK

    res = query(2 * n - 1, 2 * n - 2);

    RES_CHECK

    res = 2 * n - 3;
}

int main() {
    cin >> t;

    while (t--) {
        res = 0;
        solve();
        cout << "! " << res << endl;
    }

    return 0;
}
