#include <bits/stdc++.h>

using namespace std;

int n, c, k;
int a, b;
priority_queue<int, vector<int>, greater<int>> shit;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> k;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        if (a >= k) {
            ++res;
            continue;
        }

        if (b == 0) {
            continue;
        }

        int sessions = (k - a) / b + (((k - a) % b) ? 1 : 0);

            shit.push(sessions);
    }

    while (!shit.empty() && (c > 0)) {
        if (shit.top() > c) break;
        c -= shit.top();
        ++res;

        shit.pop();
    }

    cout << res << endl;

    return 0;
}
