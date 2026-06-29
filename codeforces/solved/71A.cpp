#include <iostream>
#include <string>

int main() {
    int n;
    std::string in;
    std::string out;

    std::cin >> n;

    while (n--) {
        std::cin >> in;

        if (in.length() > 10) {
            out.push_back(in.at(0));
            out.append(std::to_string(in.length() - 2));
            out.push_back(in.at(in.length() - 1));
            out.append("\n");

        } else {
            out.append(in);
            out.push_back('\n');
        }
    }

    std::cout << out;

    return 0;
}
