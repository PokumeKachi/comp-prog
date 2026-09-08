#include <bits/stdc++.h>

using namespace std;

long long sumFromAtoB(long long a, long long b, long long step) {
    long long n = (b - a) / step + 1;
    return n * (a + b) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res = "";

    while (t--) {
        long long x, y, k;

        cin >> x >> y >> k;

        long long result = 0;

        long long a = y;
        long long b = x;

        while (k > 0) {
            long long c = a / b;
            long long d = a % b;

            if (c == 1) {
                result += d * k;
                break;
            }

            long long jump = min(d / (c - 1) + 1, k);

            a += jump;
            b += jump;

            result += sumFromAtoB((a - 1) % (b - 1), d, c - 1);

            k -= jump;
        }

        res += to_string(result) + '\n';
    }

    cout << res;

    return 0;
}
