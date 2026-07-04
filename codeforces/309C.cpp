#define INPUT_SIZE 1000005

#include <bits/stdc++.h>

using namespace std;

int n, m;
priority_queue<unsigned int> clusters;
int arrays[35] = {0};

unsigned int input;
int res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> input;

        if (input) {
            clusters.push(input);
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> input;

        ++arrays[input];
    }

    while (!clusters.empty()) {
        unsigned int cluster = clusters.top();

        clusters.pop();

        for (int i = bit_width(cluster) - 1; i >= 0 && cluster > 0; --i) {
            int array_count = arrays[i];

            if (!array_count) {
                continue;
            }

            int placeable_arrays = cluster / (1 << i);
            int actual_placed_arrays = min(placeable_arrays, array_count);

            // cout << "yea no " << placeable_arrays << ' ' <<
            // actual_placed_arrays << "\n";

            res += actual_placed_arrays;
            array_count -= actual_placed_arrays;
            cluster -= actual_placed_arrays * (1 << i);
            arrays[i] = array_count;
        }
    }

    // for (int i = 0; i < 32; ++i) {
    //     int array_count = arrays[i];
    //
    //     while (array_count > 0 && !clusters.empty()) {
    //         // cout << "yea " << clusters.top() << ' ' << i << ' ' <<
    //         // array_count << "\n";
    //         unsigned int cluster = clusters.top();
    //
    //         clusters.pop();
    //
    //         if (bit_width(cluster) < i) {
    //             continue;
    //         }
    //
    //         int placeable_arrays = cluster / (1 << (i - 1));
    //
    //         int actual_placed_arrays = min(placeable_arrays, array_count);
    //
    //         // cout << "yea no " << placeable_arrays << ' ' <<
    //         // actual_placed_arrays << "\n";
    //
    //         res += actual_placed_arrays;
    //         array_count -= actual_placed_arrays;
    //         cluster -= actual_placed_arrays * (1 << (i - 1));
    //
    //         if (cluster > 0) {
    //             clusters.push(cluster);
    //         }
    //     }
    //
    //     if (array_count > 0) {
    //         break;
    //     }
    // }

    // cout << '\n';
    //
    // for (int i = 0; i < 5; ++i) {
    //     cout << i << ' ' << clusters[i] << '\n';
    // }
    //
    // cout << '\n';

    // for (int i = 0; i < 32; ++i) {
    //     int array_count = arrays[i];
    //
    //     if (array_count) {
    //         for (int j = i; j < 32; ++j) {
    //             int max_arrays_per_cluster = j / i;
    //
    //             if (clusters[j] * max_arrays_per_cluster < array_count) {
    //                 // cout << "case 1: " << i << ' ' << j << ' ' <<
    //                 array_count
    //                      // << '\n';
    //
    //                 array_count -= clusters[j] * max_arrays_per_cluster;
    //                 res += clusters[j] * max_arrays_per_cluster;
    //                 clusters[j] = 0;
    //
    //                 // cout << "after : " << i << ' ' << j << ' ' <<
    //                 array_count
    //                      // << "\n\n";
    //             } else {
    //                 clusters[j] -= (array_count + max_arrays_per_cluster - 1)
    //                 /
    //                                max_arrays_per_cluster;
    //                 res += array_count;
    //                 array_count = 0;
    //                 // cout << "case 2: " << i << ' ' << j << ' ' <<
    //                 clusters[j] << "\n\n"; break;
    //             }
    //         }
    //
    //         if (array_count) {
    //             break;
    //         }
    //     }
    // }

    cout << res << '\n';

    return 0;
}
