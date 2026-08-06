#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    pair<int, int> laptops[100'005];

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> laptops[i].first >> laptops[i].second;
    }

    sort(laptops, laptops + n,
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first < b.first;
         });

    for (int i = 1; i < n; ++i) {
        if (laptops[i].first > laptops[i - 1].first && laptops[i].second < laptops[i - 1].second) {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";

    return 0;
}
