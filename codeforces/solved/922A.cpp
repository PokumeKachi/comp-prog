#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;

    cin >> x >> y;

    int operationOneCount = y - 1;
    int remainingCopies = x - operationOneCount;

    if (y == 0) {
        cout << "No";
        return 0;
    }

    if (y == 1 && x > 0) {
        cout << "No";
        return 0;
    }

    if (remainingCopies >= 0 && !(remainingCopies & 1)) {
        cout << "Yes";
        return 0;
    }

    cout << "No";

    return 0;
}
