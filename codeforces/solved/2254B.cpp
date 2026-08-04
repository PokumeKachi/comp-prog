#include <bits/stdc++.h>

#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string res;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        vector<pair<int, char>> record;

        char lastChar = s[0];
        int length = 1;
        int compressedLength = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == lastChar) {
                ++length;
            } else {
                record.push_back({ length, lastChar });
                ++compressedLength;
                lastChar = s[i];
                length = 1;
            }
        }

        record.push_back({ length, lastChar });
        ++compressedLength;

        int lengthRes = compressedLength;

        // cout << "compressedLength is " << compressedLength << '\n';

        for (int i = 1; i < record.size() - 1; ++i) {
            pair<int, char> block = record[i];
            if (block.first == 1) {
                if (record[i - 1].second == record[i + 1].second) {
                    lengthRes = min(lengthRes, compressedLength - 2);
                    break;
                } else {
                    lengthRes = min(lengthRes, compressedLength - 1);
                }
            }
        }

        res += to_string(lengthRes) + '\n';
    }

    cout << res;

    return 0;
}
