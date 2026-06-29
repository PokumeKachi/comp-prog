#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int res = 0;

    for (int i = 0; i < a.length(); ++i) {
        int char1 = tolower(a.at(i));
        int char2 = tolower(b.at(i));

        if (char1 ^ char2) {
            if (char1 < char2) {
                res = -1;
            } else {
                res = 1;
            }

            break;
        }
    }

    std::cout << res;

    return 0;
}
