#include <bits/stdc++.h>

#include <functional>
#include <queue>
#include <string>

using namespace std;

struct Player {
    int value;
    int oldIndex;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    Player a[200'005];

    string res;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].value;
            a[i].oldIndex = i;
        }

        sort(a, a + n, [](const Player& a1, const Player& b) {
            return a1.value < b.value;
        });

        long long currentSum = 0;

        int start = 0;

        for (int i = 0; i < n - 1; ++i) {
            currentSum += a[i].value;

            if (currentSum < a[i + 1].value) {
                start = i + 1;
            }
        }

        priority_queue<int, vector<int>, greater<int>> finalIndexes;

        for (int i = start; i < n; ++i) {
            finalIndexes.push(a[i].oldIndex);
        }

        res += to_string(finalIndexes.size()) + '\n';

        for (int i = start; i < n; ++i) {
            res += to_string(finalIndexes.top() + 1) + ' ';
            finalIndexes.pop();
        }

        res += '\n';
    }

    cout << res;

    return 0;
}
