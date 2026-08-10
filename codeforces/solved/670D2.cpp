#include <bits/stdc++.h>

using namespace std;

struct Ingredient {
    int required;
    int has;
    int canBeMade;
    int leftover;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    Ingredient ingredients[100'005];

    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i].required;
    }

    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i].has;
        ingredients[i].canBeMade = ingredients[i].has / ingredients[i].required;
        ingredients[i].leftover = ingredients[i].has % ingredients[i].required;
    }

    sort(ingredients, ingredients + n,
         [](const Ingredient& a, const Ingredient& b) {
             return a.canBeMade < b.canBeMade;
         });

    long long costSoFar = ingredients[0].required;
    long long cookies = ingredients[0].canBeMade;
    long long currentLeftover = ingredients[0].leftover;

    long long remainingPowder = k;

    for (int i = 1; i < n; ++i) {
        Ingredient current = ingredients[i];

        if (current.canBeMade > cookies) {
            long long targetCookies = current.canBeMade - cookies;
            long long actualCookies =
                (remainingPowder + currentLeftover) / costSoFar;

            if (actualCookies >= targetCookies) {
                remainingPowder -= targetCookies * costSoFar - currentLeftover;
                cookies = current.canBeMade;
                currentLeftover = 0;
            } else {
                // WE HAVE FOUND AN ANSWER
                cout << cookies + actualCookies;
                return 0;
            }
        }

        costSoFar += current.required;
        currentLeftover += ingredients[i].leftover;
    }

    if ((currentLeftover + remainingPowder) >= costSoFar) {
        ++cookies;
        remainingPowder -= costSoFar - currentLeftover;
    }

    cookies += remainingPowder / costSoFar;

    cout << cookies;

    return 0;
}
