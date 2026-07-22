#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;

    cin >> t;

    string output;

    for (long long i = 0; i < t; ++i) {
        long long count;

        cin >> count;

        long long sum = 0;
        long long input;
        bool shit = true;

        for (long long j = 0; j < count; ++j) {
            cin >> input;

            if (!shit) continue;

            sum += input;

            if (sum < (j + 1) * (j + 2) / 2) {
                output.append("NO\n");
                shit = false;
            }
        }

        if (shit) output.append("YES\n");
    }

    cout << output;

    return 0;
}
