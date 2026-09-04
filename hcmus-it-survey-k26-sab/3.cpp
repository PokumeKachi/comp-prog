#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    int count[30] = {0};

    for (const char &c: s) {
        ++count[c - 'A'];
    }

    int oddCounts = 0;

    for (int i = 0; i < 26; ++i) {
        if (count[i] & 1) ++oddCounts;
    }

    cout << oddCounts / 2;

    return 0;
}
