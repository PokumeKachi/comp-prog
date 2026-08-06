#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    --k;

    pair<int, int> team[55];

    for (int i = 0; i < n; ++i) {
        cin >> team[i].first >> team[i].second;
    }

    sort(team, team + n, [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });

    int targetProblems = team[k].first;
    int targetPenalty = team[k].second;

    int res = 1;

    int i = k;

    while (--i >= 0) {
        if (team[i].first != targetProblems || team[i].second != targetPenalty) break;
        ++res;
    }

    i = k;

    while (++i < n) {
        if (team[i].first != targetProblems || team[i].second != targetPenalty) break;
        ++res;
    }

    cout << res;

    return 0;
}
