#include <iostream>

int main() {
    int n;

    int res = 0;

    std::cin >> n;

    while (n--) {
        int a, b, c;

        std::cin >> a >> b >> c;

        if (a + b + c > 1) {
            res++;
        }
    }

    std::cout << res;

    return 0;
}
