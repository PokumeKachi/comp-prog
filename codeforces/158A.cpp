#include <stdio.h>

#define SIZE 105

int CACHE[SIZE] = {0};
int n, k;

int i, j;

int res;

int main() {
    scanf("%d%d", &n, &k);

    res = 0;

    for (i = 0; i < n; ++i) {
        scanf("%d", &j);

        if (j) {
            ++CACHE[j];
        }
    }

    for (i = SIZE - 1; i > 0; --i) {
        res += CACHE[i];
        k -= CACHE[i];
        if (k <= 0) break;
    }

    printf("%d", res);

    return 0;
}
