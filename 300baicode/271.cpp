#include <bits/stdc++.h>

using namespace std;

string res;

int main() {
    string baseTime;

    cin >> baseTime;

    string year = baseTime.substr(0, 4);
    string month = baseTime.substr(5, 2);
    string day = baseTime.substr(8, 2);

    cin >> baseTime;

    string hour = baseTime.substr(0, 2);
    string minute = baseTime.substr(3, 2);
    string second = baseTime.substr(6, 2);

    string format;
    cin.ignore();
    getline(cin, format);

    string currentToken;

    auto handleToken = [&](const string& token) {
        if (token == "yyyy") res += year;
        if (token == "yy") res += year.substr(2,2);
        if (token == "MM") res += month;
        if (token == "M") res += month[1];
        if (token == "dd") res += day;
        if (token == "d") res += day[1];
        if (token == "hh") res += hour;
        if (token == "h") res += hour[1];
        if (token == "mm") res += minute;
        if (token == "m") res += minute[1];
        if (token == "ss") res += second;
        if (token == "s") res += second[1];
    };

    for (const char& c : format) {
        if (c ^ 'y' && c ^ 'M' && c ^ 'm' && c ^ 'd' && c ^ 'h' && c ^ 's') {
            handleToken(currentToken);
            res += c;
            currentToken = "";
        } else {
            currentToken += c;
        }
    }

    handleToken(currentToken);

    cout << res;

    return 0;
}
