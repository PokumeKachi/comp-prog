#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    bool primes[200'005];
    fill(primes, primes + 200005, true);

    primes[0] = primes[1] = false;

    for (int j = 4; j < 200'005; j += 2) {
        primes[j] = false;
    }

    for (int i = 3; i * i < 200'005; i += 2) {
        if (primes[i]) {
            for (int j = i * i; j < 200'005; j += i) {
                primes[j] = false;
            }
        }
    }

    while (t--) {
        int n;
        cin >> n;

        res += primes[n + 1] ? "YES" : "NO";

        res += '\n';
    }

    cout << res;

    return 0;
}
