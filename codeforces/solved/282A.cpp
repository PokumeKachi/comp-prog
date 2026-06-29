#include <iostream>
#include <string>

int main() {
    int n;
    std::string arg;
    int res = 0;

    std::cin >> n;

    while (n--) {
        std::cin >> arg;

        if (arg.at(1) == '-') {
            --res;
        } else {
            ++res;
        }
    }

    std::cout << res;

    return 0;
}
