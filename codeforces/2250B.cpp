#include <bits/stdc++.h>

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

        int num0MaxPair = usableNum0 - 1;
        int num1MaxPair = usableNum1 - 1;

        if (!k) {
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                    res.append("0");
                } else {
                    res.append("1");
                }
            }
        } else if (num0MaxPair + num1MaxPair >= k) {
            int remainingPairs = k;
            int remaingChars = n;

            bool lastWas1 = true;

            while (remainingPairs) {
                if (num0MaxPair) {
                    if (lastWas1) {
                        lastWas1 = false;
                        res.append("00");
                        remainingPairs -= 1;
                        remaingChars -= 2;
                    } else {
                        res.append("0");
                        remainingPairs -= 1;
                        remaingChars -= 1;
                    }

                    num0MaxPair--;
                } else {
                    if (lastWas1) {
                        res.append("1");
                        remainingPairs -= 1;
                        remaingChars -= 1;
                    } else {
                        lastWas1 = true;
                        res.append("11");
                        remainingPairs -= 1;
                        remaingChars -= 2;
                    }
                    num1MaxPair--;
                }
            }

            while (remaingChars--) {
                if (lastWas1) {
                    res.append("0");
                } else {
                    res.append("1");
                }

                lastWas1 = !lastWas1;
            }
        } else {
            res.append("-1");
        }

        res.append("\n");
    }

    cout << res;

    return 0;
}
