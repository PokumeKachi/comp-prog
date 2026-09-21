#include <bits/stdc++.h>

#include <string>

#define SIEVE_MAX 300'000

using namespace std;

std::array<int, SIEVE_MAX> sieveBool;
std::array<long long, 100'000> primes;
int primeCounter = 1;

long long getCost(long long x, long long k) {
    long long recordX = x, recordK = k;

    cout << "PROCESSING " << x << '\n';

    if (x <= k) return 0;

    int i = upper_bound(primes.begin(), primes.begin() + primeCounter, x) -
            primes.begin();

    while (i--) {
        if (x % primes[i] == 0) {
            cout << "FOUND LARGEST PRIME FOR " << x << " IT IS " << primes[i]
            << '\n';
            x /= primes[i];
            break;
        }
    }

    long long cost = 1;
    long long currentCount = 1;

    i = 0;

    while (x > k) {
        currentCount *= sieveBool[x];
        cost += currentCount;
        x /= sieveBool[x];
    }

    cout << recordX << ' ' << recordK << ' ' << cost << '\n';

    return cost;
}

void sieveSetup() {
    std::fill(sieveBool.begin(), sieveBool.end(), 0);
    primes[0] = 2;
    sieveBool[0] = sieveBool[1] = 1;

    for (int j = 2 * 2; j < SIEVE_MAX; j += 2) {
        sieveBool[j] = 2;
    }

    int lastI;

    for (int i = 3; i * i < SIEVE_MAX; i += 2) {
        lastI = i;
        if (sieveBool[i] == 0) {
            primes[primeCounter++] = i;
            for (int j = i * i; j < SIEVE_MAX; j += i) {
                sieveBool[j] = i;
            }
        }
    }

    for (int i = lastI; i < SIEVE_MAX; i += 2) {
        if (sieveBool[i] == 0) primes[primeCounter++] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieveSetup();

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n, k;

        cin >> n >> k;

        long long a;
        multiset<long long> ms;

        for (int i = 0; i < n; ++i) {
            cin >> a;
            ms.insert(a);
        }

        long long f = 0;

        for (auto it = ms.begin(); it != ms.end();) {
            long long x = *it;

            f += ms.count(x) * getCost(x, k);

            it = ms.upper_bound(x);
        }

        res += to_string(f) + '\n';
    }

    cout << res;

    return 0;
}
