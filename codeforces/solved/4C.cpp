#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> record;

    string res;

    string input;

    while (n--) {
        cin >> input;

        int count = record[input]++;

        if (count) {
            res += input + to_string(count);
        } else {
            res += "OK";
        }

        res += '\n';
    }

    cout << res;

    return 0;
}
