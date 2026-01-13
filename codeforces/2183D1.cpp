#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <utility>

#define SIZE 200005

uint16_t t;
uint32_t n, u, v;
int i, j, k;
int res;

typedef std::pair<std::uint32_t, std::uint32_t> mypair;

std::array<mypair, SIZE> TREE;
std::array<uint32_t, SIZE> DP;

bool compare(const mypair& a, const mypair& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::cin >> t;

    while (t--) {
        std::cin >> n;

        TREE[0] = {1, 1};

        for (i = 1; i < n; ++i) {
            std::cin >> j >> k;

            TREE[i] = {std::min(j, k), std::max(j, k)};
        }

        std::sort(TREE.begin() + 1, TREE.begin() + n, compare);

        uint32_t DATA_SIZE = TREE[n - 1].second + 5;

        std::fill(DP.begin(), DP.begin() + DATA_SIZE, 0);
        // std::cout << "start this\n";

        for (i = 0; i < n; ++i) {
            // std::cout << TREE[i].first << " " << TREE[i].second << '\n';
            auto* start = DP.begin() + TREE[i].first;
            auto* end = DP.begin() + TREE[i].second;
            // std::transform(start, end, start,
            //                [](const int& x) { return x + 1; });

            *start += 1;
            // *(start + 1) += 1;
            // *(end - 2) += 1;
            // *(end - 1) += 1;
            *end += 1;
            // *end += 1;
            for (j = 0; j < DATA_SIZE; ++j) {
                // std::cout << j << ' ' << DP[j] << '\n';
            }
            // std::cout << '\n';
        }
        // std::cout << "end this\n";

        // for (i = 0; i < DATA_SIZE; ++i) {
        //     std::cout << i << ' ' << DP[i] << '\n';
        // }

        std::cout << *std::max_element(DP.begin(), DP.begin() + DATA_SIZE)
                  << '\n';

        // while (n) {
        //     i = 0;
        //
        //     while (i != n) {
        //         i = std::upper_bound(TREE.begin() + i, TREE.begin() + n,
        //                              TREE[i].second, compare) -
        //             TREE.begin();
        //     }
        // }
    }

    return 0;
}
