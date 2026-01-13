
#include <cstdio>
#include <iostream>
#include <string>

int t, x, n;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    std::cin >> t;

    std::string res = "";

    while (t--) {
        std::cin >> x >> n;

        res += ' ';

        if (n % 2) {
            res += std::to_string(x);
        } else {
            res += '0';
        }

        res += '\n';
    }

    std::cout << res;

    return 0;
}
