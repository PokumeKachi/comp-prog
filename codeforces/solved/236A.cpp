#include <bitset>
#include <iostream>
#include <string>

std::bitset<27> record;

int main() {
    std::string a;
    std::cin >> a;

    for (int i = 0; i < a.length(); ++i) {
        record.set(a.at(i) - 'a');
    }

    if (record.count() & 1) {
        std::cout << "IGNORE HIM!";
    } else {
        std::cout << "CHAT WITH HER!";
    }

    return 0;
}
