#include <bits/stdc++.h>

#define SIEVE_MAX 300'000

using namespace std;

std::array<long long, SIEVE_MAX> SPF;
std::array<long long, SIEVE_MAX> GPF;
long long primeCounter = 1;

void sieveSetup() {
    fill(SPF.begin(), SPF.end(), 1);

    for (long long j = 2; j < SIEVE_MAX; j += 2) {
        SPF[j] = GPF[j] = 2;
    }

    long long lastI;

    for (long long i = 3; (i << 1) < SIEVE_MAX; i += 2) {
        lastI = i;
        if (SPF[i] == 1) {
            SPF[i] = GPF[i] = i;
            for (long long j = i + i; j < SIEVE_MAX; j += i) {
                GPF[j] = i;

                if (SPF[j] == 1) SPF[j] = i;
            }
        }
    }

    for (long long i = lastI; i < SIEVE_MAX; i += 2) {
        if (SPF[i] == 1) {
            SPF[i] = GPF[i] = i;
            for (long long j = i + i; j < SIEVE_MAX; j += i) {
                GPF[j] = i;

                if (SPF[j] == 1) SPF[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieveSetup();

    long long t;
    cin >> t;

    string res;

    while (t--) {
        long long n, k;

        cin >> n >> k;

        vector<long long> dp(n + 1);

        fill(dp.begin(), dp.begin() + k + 1, 0);

        for (long long x = k + 1; x <= n; ++x) {
            dp[x] = LLONG_MAX;

            long long y = x;
            while (y > 1) {
                long long p = SPF[y];

                dp[x] = min(dp[x], p * dp[x / p] + 1);

                while (y % p == 0) y /= p;
            }
        }

        long long f = 0;

        long long a;

        for (long long i = 0; i < n; ++i) {
            cin >> a;

            f += dp[a];
        }

        res += to_string(f) + '\n';
    }

    cout << res;

    return 0;
}
