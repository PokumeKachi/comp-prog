#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f;

    cin >> n >> f;

    int products[100'005];
    int clients[100'005];

    long long baseProfit = 0;
    priority_queue<int> profit;

    for (int i = 0; i < n; ++i) {
        cin >> products[i] >> clients[i];

        if (products[i] >= clients[i]) {
            baseProfit += clients[i];
        } else {
            baseProfit += products[i];

            if ((products[i] << 1) <= clients[i]) {
                profit.push(products[i]);
            } else {
                profit.push(clients[i] - products[i]);
            }
        }
    }

    for (int i = 0; i < f; ++i) {
        if (profit.empty()) break;
        baseProfit += profit.top();
        profit.pop();
    }

    cout << baseProfit;

    return 0;
}
