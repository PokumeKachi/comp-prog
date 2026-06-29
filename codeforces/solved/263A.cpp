#include <iostream>

int main() {
    int n, in;

    n = 0;

    while (true) {
        std::cin >> in;

        if (in) break;

        ++n;
    }

    int x, y;

    x = n % 5;
    y = n / 5;

    std::cout << std::abs(x - 2) + std::abs(y - 2);

    return 0;
}
