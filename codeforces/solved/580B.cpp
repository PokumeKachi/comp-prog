#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

struct Friend {
    int money;
    int friendship;
};

bool compareFunc(const Friend &a, const Friend &b) {
    return a.money < b.money;
}

bool lowerFunc(const Friend &a, const int &b) {
    return a.money < b;
}

bool upperFunc(const int &a, const Friend &b) {
    return a < b.money;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    Friend friends[100'005];

    long long friendshipPrefixSum[100'005];
    friendshipPrefixSum[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> friends[i].money >> friends[i].friendship;
    }

    sort(friends, friends + n, compareFunc);

    for (int i = 0; i < n; ++i) {
        friendshipPrefixSum[i + 1] =
            friendshipPrefixSum[i] + friends[i].friendship;
    }

    long long res = 0;

    for (int i = 0; i < n;) {
        int range = lower_bound(friends, friends + n, friends[i].money + d, lowerFunc) - friends;

        res = max(res, friendshipPrefixSum[range] - friendshipPrefixSum[i]);

        i = lower_bound(friends, friends + n, friends[i].money + 1, lowerFunc) - friends;
    }

    cout << res;

    return 0;
}
