#include <bitset>
#include <iostream>
#include <string>

int record[3] = {0};

int main() {
    std::string in;

    std::cin >> in;

    for (int i = 0; i < in.length(); i += 2) {
        ++record[in.at(i) - '1'];
    }

    std::string out;

    if (record[0]--) {
        out.push_back('1');
    } else if (record[1]--) {
        out.push_back('2');
    } else if (record[2]--) {
        out.push_back('3');
    }

    while (record[0]-- > 0) {
        out.append("+1");
    }

    while (record[1]-- > 0) {
        out.append("+2");
    }

    while (record[2]-- > 0) {
        out.append("+3");
    }

    std::cout << out;

    return 0;
}
