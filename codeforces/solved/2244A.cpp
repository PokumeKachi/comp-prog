#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    int length;
    string input;
    string output;

    while (t--) {
        cin >> length >> input;

        int longest_shi = 0;
        int current_shi = 0;

        for (const char& c : input) {
            if (c == '#') {
                longest_shi = max(longest_shi, ++current_shi);
            } else {
                longest_shi = max(longest_shi, current_shi);
                current_shi = 0;
            }
        }

        output.append(to_string((longest_shi + 1) >> 1) + '\n');
    }

    cout << output;

    return 0;
}
