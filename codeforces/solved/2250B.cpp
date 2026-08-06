#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string res = "";

    cin >> t;

    while (t--) {
        int n, k;

        cin >> n >> k;

        int usableNum0 = (n) >> 1;
        int usableNum1 = n - usableNum0;

        // 1 bits will always be greater or equal

        int num0MaxPair = usableNum0 - 1;
        int num1MaxPair = usableNum1 - 1;

        if (num0MaxPair + num1MaxPair >= k) {
            int needed0Pairs = k >> 1;
            int needed1Pairs = k - needed0Pairs;

            int remaingChars = n - (needed0Pairs + 1) - (needed1Pairs + 1);

            res += string(needed0Pairs + 1, '0');
            res += string(needed1Pairs + 1, '1');

            bool lastWas1 = true;

            while (remaingChars--) {
                if (lastWas1) {
                    res += '0';
                } else {
                    res += '1';
                }

                lastWas1 = !lastWas1;
            }
        } else {
            res += "-1";
        }

        res += '\n';
    }

    cout << res;

    return 0;
}
