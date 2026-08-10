#include <bits/stdc++.h>

#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int a[200'005];
        int b[200'005];

        for (int i = 0; i < x; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < y; ++i) {
            cin >> b[i];
        }

        int record[200'005] = {0};
        int case1 = 0;
        int remainingShi = max(0, x - n - 2);

        for (int i = 0; i < min(x, n); ++i) {
            int value = a[x - 1 - i];
            case1 += value;
            record[value] = 1;

            res += "case 1 a " + to_string(value) + '\n';
        }

        int filled = 0;

        for (int i = 0; i < min(m, y) && filled < m - 1; ++i) {
            int value = b[y - 1 - i];
            if (record[value]) {
                if (remainingShi >= 0 && i < y - 1) {
                    if (a[remainingShi] > b[y - 1 - i - 1]) {
                        res += "case 1 a " + to_string(a[remainingShi]) + '\n';
                        case1 += a[remainingShi];
                        record[a[remainingShi--]] = 1;
                        ++filled;
                    }
                }
            } else {
                case1 += value;
                res += "case 1 b " + to_string(value) + '\n';
                ++filled;
            }
        }

        fill(record, record + 200005, 0);
        int case2 = 0;
        remainingShi = max(0, y - m - 2);

        for (int i = 0; i < min(y, m); ++i) {
            case2 += b[y - 1 - i];
            record[b[y - 1 - i]] = 1;

            res += "case 2 b " + to_string(b[y - 1 - i]) + '\n';
        }

        filled = 0;

        for (int i = 0; i < min(n, x) && filled < n - 1; ++i) {
            int value = a[x - 1 - i];
            if (record[value]) {
                if (remainingShi >= 0 && i < x - 1) {
                    if (b[remainingShi] > a[x - 1 - i - 1]) {
                        res += "case 2 b " + to_string(b[remainingShi]) + '\n';
                        case2 += b[remainingShi];
                        record[b[remainingShi--]] = 1;
                        ++filled;
                    }
                }
            } else {
                case2 += value;
                res += "case 2 a " + to_string(value) + '\n';
                ++filled;
            }
        }

        res += to_string(max(case1, case2));
        res += '\n';
    }

    cout << res;

    return 0;
}
