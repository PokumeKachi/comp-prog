#include <bits/stdc++.h>

#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    string res;

    while (t--) {
        long long n;
        std::array<long long, 200'005> b;

        cin >> n;

        for (long long i = 0; i < n; ++i) {
            cin >> b[i];
        }

        std::array<long long, 200'005> sorted = b;

        sort(sorted.begin(), sorted.begin() + n);

        std::vector<std::pair<long long, long long>> freq;

        for (long long i = 0; i < n;) {
            long long count = 0;
            long long element = sorted[i];

            while (i < n && element == sorted[i]) {
                ++i;
                ++count;
            }

            freq.push_back({element, count});
        }

        if (freq[0].first != 0) {
            res += "-1\n";
            continue;
        }

        if (freq.size() == 1) {
            for (long long i = 0; i < freq[0].second; ++i) {
                res += "1 ";
            }
            res += '\n';
            continue;
        }

        unordered_map<long long, long long> record;

        long long lastElement = -1;

        for (long long i = 1; i < freq.size(); ++i) {
            if ((freq[i].first - freq[i - 1].first) % freq[i - 1].second) {
                res += "-1";
                goto exit;
            }

            long long thisElement =
                (freq[i].first - freq[i - 1].first) / freq[i - 1].second;

            if (lastElement != -1) {
                if (lastElement >= thisElement) {
                    res += "-1";
                    goto exit;
                }
            }
            lastElement = thisElement;

            record[freq[i - 1].first] = thisElement;
        }

        record[freq[freq.size() - 1].first] =
            record[freq[freq.size() - 2].first] + 1;

        for (long long i = 0; i < n; ++i) {
            res += to_string(record[b[i]]) + ' ';
        }
    exit:
        res += '\n';
    }

    cout << res;

    return 0;
}
