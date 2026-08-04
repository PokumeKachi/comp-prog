#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;

    cin >> input;

    string res = "";

    for (const char c: input) {
        char realC = tolower(c);

        if (realC != 'a' && realC != 'o' && realC != 'y' && realC != 'e' && realC != 'u' && realC != 'i') {
            res.append(".");
            res += realC;
        }
    }

    cout << res;

    return 0;
}
