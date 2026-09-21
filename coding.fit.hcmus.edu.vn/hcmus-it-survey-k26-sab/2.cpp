#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int last = -1;
    int input;

    cin >> n;

    int res = 0;
    int currentLength = 0;

    for (int i = 0; i < n; ++i) {
        cin >> input;

        if (last == -1) {
            currentLength = 1;
        } else {
            if (last < input) {
                ++currentLength;
            } else {
                currentLength = 1;
            }
        }
        res = max(res, currentLength);
        last = input;
    }

    cout << res;

    return 0;
}
