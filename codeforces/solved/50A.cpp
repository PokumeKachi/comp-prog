#include <iostream>

int main() {
    int m, n;
    int a, b;

    int res;

    std::cin >> m >> n;

    a = std::max(m, n);
    b = std::min(m, n);

    if (a & 1) {
        res = (a >> 1) * b + (b >> 1);

    } else {
        res = (a >> 1) * b;
    }

    std::cout << res;

    return 0;
}
